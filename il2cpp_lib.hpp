#pragma once
#include "sapphire_importer.hpp"
#include "pattern.hpp"
#include <map>
#include <iostream>
#include <fstream>
#include <string>

#define CREATE_TYPE( name, args ) using il2cpp_##name = args; inline il2cpp_##name name;
#define ASSIGN_TYPE( name ) name = SAPPHIRE_TYPE( L"GameAssembly.dll", il2cpp_##name );

#define SAPPHIRE_FIELD( klass, name ) static std::uintptr_t name = il2cpp_lib::field( klass, #name, true );
#define SAPPHIRE_TYPE_OBJECT( ns, name ) il2cpp_lib::type_object( ns, name )
#define SAPPHIRE_ICALL( fn_name, name, args ) static auto fn_name = reinterpret_cast< args >( il2cpp_lib::resolve_icall( name ) );

#define SAPPHIRE_METHOD( fn_name, name, arg_count, arg_name, selected_arg, args ) \
	static auto fn_name = reinterpret_cast< args >( *reinterpret_cast< std::uintptr_t* >( il2cpp_lib::method( name, arg_count, arg_name, selected_arg ) ) )
uintptr_t hook_virtual_function(const char* classname, const char* function_to_hook, void* our_func, int param_count, const char* name_space = (""));

namespace il2cpp_lib
{
	struct sanitized_method_t {
		std::string ns, kl, mt;
	};
	class il2cppstring
	{
	public:
		char pad_0000[0x10];
		int len;
		wchar_t buffer[0];

		static il2cppstring* New(const char* str);
	};

	CREATE_TYPE(method_get_name, const char* (*)(std::uintptr_t));
	CREATE_TYPE(method_get_param_name, const char* (*)(std::uintptr_t, std::uint32_t index));
	CREATE_TYPE(domain_get, std::uintptr_t(*)());
	CREATE_TYPE(class_get_methods, std::uintptr_t(*)(std::uintptr_t, std::uintptr_t*));
	CREATE_TYPE(method_get_param_count, int (*)(std::uintptr_t));
	CREATE_TYPE(assembly_get_image, std::uintptr_t(*)(std::uintptr_t));
	CREATE_TYPE(domain_get_assemblies, std::uintptr_t* (*)(void* domain, std::uintptr_t* size));
	CREATE_TYPE(object_new, std::uintptr_t(*)(std::uintptr_t));
	CREATE_TYPE(class_from_name, std::uintptr_t(*)(std::uintptr_t, const char*, const char*));
	CREATE_TYPE(resolve_icall, std::uintptr_t(*)(const char*));
	CREATE_TYPE(field_static_get_value, std::uintptr_t(*)(std::uintptr_t, std::uintptr_t*));
	CREATE_TYPE(class_get_fields, std::uintptr_t(*)(std::uintptr_t, std::uintptr_t*));
	CREATE_TYPE(field_get_offset, std::uintptr_t(*)(std::uintptr_t));
	CREATE_TYPE(string_new_wrapper, std::uintptr_t(*)(const char*));
	CREATE_TYPE(class_get_type, std::uintptr_t(*)(std::uintptr_t));
	CREATE_TYPE(type_get_object, std::uintptr_t(*)(std::uintptr_t));
	CREATE_TYPE(method_get_return_type, const char* (*)(std::uintptr_t));
	CREATE_TYPE(class_get_method_from_name, std::uintptr_t(*)(std::uintptr_t, const char*, int));
	CREATE_TYPE(new_string, il2cppstring* (*)(const char*));

	inline void init() {
		ASSIGN_TYPE(method_get_name);
		ASSIGN_TYPE(method_get_param_name);
		ASSIGN_TYPE(domain_get);
		ASSIGN_TYPE(class_get_methods);
		ASSIGN_TYPE(method_get_param_count);
		ASSIGN_TYPE(assembly_get_image);
		ASSIGN_TYPE(domain_get_assemblies);
		ASSIGN_TYPE(object_new);
		ASSIGN_TYPE(class_from_name);
		ASSIGN_TYPE(resolve_icall);
		ASSIGN_TYPE(field_static_get_value);
		ASSIGN_TYPE(class_get_fields);
		ASSIGN_TYPE(field_get_offset);
		ASSIGN_TYPE(string_new_wrapper);
		ASSIGN_TYPE(class_get_type);
		ASSIGN_TYPE(type_get_object);
		ASSIGN_TYPE(method_get_return_type);
		ASSIGN_TYPE(class_get_method_from_name);
		ASSIGN_TYPE(new_string);
	}

	inline auto find_class(const char* name, const char* name_space = "") -> const std::uintptr_t {

		const auto domain = domain_get();
		if (!domain)
			return 0;
		std::uintptr_t assembly_count{ 0 };
		std::uintptr_t* assemblies;
		assemblies = domain_get_assemblies((void*)domain, &assembly_count);

		for (size_t idx{ 0 }; idx < assembly_count; idx++) {
			const auto img = assembly_get_image(assemblies[idx]);
			const auto kl = class_from_name(img, name_space, name);
			if (!kl)
				continue;

			return kl;
		}

		return 0;
	}


	inline auto type_object(const char* name_space, const char* name) -> const uintptr_t
	{
		auto klass = find_class(name, name_space);
		return type_get_object(class_get_type(klass));
	}

	uintptr_t GetType(const char* space, const char* name) {
		return type_object(space, name);
	}
	// im sorry this is messy but its a lot cleaner in the end.
	inline auto sanitize_method_name(const std::string name) -> sanitized_method_t {
		std::string ns, kl, method_name;

		if (auto ns_break = name.find("::"))
			ns = name.substr(0, ns_break);

		if (name.find("::") == std::string::npos)
			ns = "";

		if (name.find("::")) {
			kl = name.substr(name.find("::", 2) + 2);
			kl = kl.substr(0, kl.find(".", 0));
		}

		if (name.find("::") == std::string::npos)
			kl = name.substr(0, name.find(".", 0));

		method_name = name.substr(name.find(".", 0) + 1);

		if (method_name.find("()"))
			method_name.erase(method_name.find("()"), 2);

		return { ns, kl, method_name };
	}

	inline auto method1(const std::string name, int argument_number = -1, const char* arg_name = "", int selected_argument = -1) -> const std::uintptr_t {
		std::uintptr_t iter{};

		const auto st = sanitize_method_name(name);
		const auto klass = find_class(st.kl.c_str(), st.ns.c_str());

		while (auto method = class_get_methods(klass, &iter)) {

			const auto fn_name = *reinterpret_cast<const char**>(method + 0x10);

			if (utl::crt::string::strcmp(fn_name, st.mt.c_str())) {
				auto method_count = method_get_param_count(method);
				if (argument_number >= 0 && method_count != argument_number)
					continue;

				if (selected_argument >= 0 && arg_name) {
					auto args = *reinterpret_cast<std::uintptr_t*>(method + 0x28);

					if (selected_argument > method_count)
						continue;

					char* argname;

					if (method_count > 0)
						argname = *reinterpret_cast<char**>(args + (selected_argument - 1) * 0x18);
					else
						argname = (char*)("-");

					if (!argname || !utl::crt::string::strcmp(argname, arg_name))
						continue;
				}

				return method;
			}
		}

		return {};
	}

	inline auto method(const std::string name, int argument_number = -1, const char* arg_name = "", int selected_argument = -1) -> const std::uintptr_t {
		std::uintptr_t iter{};

		const auto st = sanitize_method_name(name);
		const auto klass = find_class(st.kl.c_str(), st.ns.c_str());

		while (auto method = class_get_methods(klass, &iter)) {

			const auto fn_name = method_get_name(method);

			if (utl::crt::string::strcmp(fn_name, st.mt.c_str())) {
				auto method_count = method_get_param_count(method);
				if (argument_number >= 0 && method_count != argument_number)
					continue;

				if (selected_argument >= 0 && arg_name) {

					if (selected_argument > method_count)
						continue;

					const char* argname;

					if (method_count > 0)
						argname = method_get_param_name(method, selected_argument - 1);
					else
						argname = (char*)("-");

					if (!argname || !utl::crt::string::strcmp(argname, arg_name))
						continue;
				}

				return method;
			}
		}

		return {};
	}
	inline auto field_internal(std::uintptr_t klass, const char* field_name, bool offset = true) -> const uintptr_t {
		auto iterator = std::uintptr_t();
		if (!klass)
			return 0;
		if (!class_get_fields)
			return 0;
		while (auto il2cpp_field = class_get_fields(klass, &iterator)) {

			const auto name = reinterpret_cast<const char*>(*reinterpret_cast<std::uintptr_t*>(il2cpp_field));
			if (!name) {
				break;
			}

			if (!utl::crt::string::strcmp(name, field_name)) {
				continue;
			}

			if (!offset) {
				return il2cpp_field;
			}

			return field_get_offset(il2cpp_field);
		}
		return 0;
	}

	inline auto field(const char* kl, const char* name, bool offset = true) -> const std::uintptr_t {

		const auto klass = find_class(kl);

		if (offset) {
			return field_internal(klass, name);
		}

		const auto _field = field_internal(klass, name, false);

		auto ret = std::uintptr_t();
		field_static_get_value(_field, &ret);
		return ret;
	}
	
	uintptr_t method3(std::string kl, std::string name, int param_count, const char* name_space = (""), bool param_check = false, int param_idx = 0, std::string param_name = "")
	{
	 
		uintptr_t klass = find_class(kl.c_str(), name_space);
		if (!klass)
		{
			std::cout << "[matrix]: Failed to init class in il2cpp::method: " << name_space << "::" << kl << std::endl;
			return NULL;
		}
		if (!param_check)
		{
			uintptr_t method = class_get_method_from_name(klass, name.c_str(), param_count);
			return method;
		}
		else
		{
			uintptr_t nrofmethods;
			uintptr_t methods;
			methods = class_get_methods(klass, &nrofmethods);
			while (methods = class_get_methods(klass, &nrofmethods))
			{
				char* method_name = *reinterpret_cast<char**>(methods + 0x10);
				//std::cout << "Method Name: " << method_name << std::endl;
				if (std::string(method_name) == name)
				{
					uintptr_t args = *reinterpret_cast<uintptr_t*>(methods + 0x28);
					char* arg_name = *reinterpret_cast<char**>(args + 1 * 0x18);
					//printf("[%s] %s", name, std::string(arg_name));
				}
			}
		}
	}

	uintptr_t hook(void* our_func, std::string kl, std::string name, int arg, const char* name_space)
	{
		//il2cpp_lib::method(name, arg_count, arg_name, selected_arg)
		auto il2cpp_method = method3(kl.c_str(), name.c_str(), arg, name_space);
		*reinterpret_cast<void**>(il2cpp_method) = our_func;

		void* written = *reinterpret_cast<void**>(il2cpp_method);
		if (written == our_func)
		{
			std::cout << "[matrix] Hooked " << kl << " successfully" << std::endl;
		}

		return il2cpp_method;
	}
	uintptr_t hook_virtual_function(const char* classname, const char* function_to_hook, void* our_func, int param_count, const char* name_space = (""))
	{
		auto methods = method3(classname, function_to_hook, param_count, name_space);
		if (!methods)
		{
			std::cout << "[matrix] Error getting method! Failed to hook " << name_space << "::" << classname << "::" << function_to_hook << std::endl;
			return NULL;
		}
		uintptr_t search = *reinterpret_cast<uintptr_t*>(methods);
		uintptr_t table = find_class(classname);

		if (search == (uintptr_t)our_func)
		{
			std::cout << "[matrix] Already hooked " << name_space << "::" << classname << "::" << function_to_hook << std::endl;
			return (uintptr_t)our_func;
		}

		for (uintptr_t i = table; i <= table + 0x10000; i += 0x1) {
			uintptr_t addr = *reinterpret_cast<uintptr_t*>(i);
			if (addr == search)
			{
				std::cout << "[matrix] Hooking " << name_space << "::" << classname << "::" << function_to_hook << " at address: 0x" << std::hex << addr << std::dec << std::endl;
				*reinterpret_cast<uintptr_t*>(i) = (uintptr_t)our_func;
				return addr;
			}
		}

		std::cout << "[matrix] Failed to hook " << name_space << "::" << classname << "::" << function_to_hook << std::endl;
	}
 

}