#define STR_MERGE_IMPL(a, b) a##b
#define STR_MERGE(a, b) STR_MERGE_IMPL(a, b)
#define MAKE_PAD(size) STR_MERGE(_pad, __COUNTER__)[size]
#define member(type, name, offset) struct {unsigned char MAKE_PAD(offset); type name;}
#define min(a,b)            (((a) < (b)) ? (a) : (b))

namespace mem1 {
	template<typename t>
	t read(uintptr_t addr) {
		if (addr < 0xffffff)
			return t();
		if (addr > 0x7fffffff0000)
			return t();

		return *reinterpret_cast<t*>(addr);
	}
	template<typename t>
	bool write(uintptr_t addr, t buffer) {
		*reinterpret_cast<t*>(addr) = buffer;
		return true;
	}
}

namespace System {
	template<typename T = void*>
	class Array1 {
	public:
		uint32_t size() {
			if (!this || (uintptr_t)this < 0xFFFFFFFF || (uintptr_t)this > 0xF000000000000000) return 0;
			return *reinterpret_cast<uint32_t*>(this + 0x18);
		}
		T get(int idx) {
			if (!this || (uintptr_t)this < 0xFFFFFFFF || (uintptr_t)this > 0xF000000000000000) return T{};
			return *reinterpret_cast<T*>(this + (0x20 + (idx * 0x8)));
		}
		void add(int idx, T value) {
			if (!this || (uintptr_t)this < 0xFFFFFFFF || (uintptr_t)this > 0xF000000000000000) return;
			*reinterpret_cast<T*>(this + (0x20 + (idx * 0x8))) = value;
		}
	};

	template<typename T = void*, typename K = void*>
	class ListDictionary1
	{
	public:
		K get_value(uint32_t idx) {
			auto listhead = *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x10);
			if (idx > 0) {
				auto n = *reinterpret_cast<uintptr_t*>(listhead + (idx * 0x20));
				return *reinterpret_cast<K*>(n + 0x18);
			}
			return mem1::read<K>(listhead + 0x18);
		}
		T get_key(uint32_t idx) {
			auto listhead = *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x10);
			if (idx > 0) {
				auto n = *reinterpret_cast<uintptr_t*>(listhead + (idx * 0x20));
				return *reinterpret_cast<T*>(n + 0x10);
			}
			return mem1::read<T>(listhead + 0x10);
		}
		int32_t size() {
			return *reinterpret_cast<int32_t*>((uintptr_t)this + 0x1C);
		}
	};
	template<typename T>
	class list1 {
	public:
		T get(uint32_t idx)
		{
			const auto internal_list = reinterpret_cast<uintptr_t>(this + 0x20);
			if (!internal_list) return 0;
			return *reinterpret_cast<T*>(internal_list + idx * sizeof(T));
		}

		T get_value(uint32_t idx)
		{
			const auto list = *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x10);
			if (!list) return 0;
			const auto internal_list = list + 0x20;
			return *reinterpret_cast<T*>(internal_list + idx * sizeof(T));
		}

		T operator[](uint32_t idx) { return get(idx); }

		const uint32_t get_size() { return *reinterpret_cast<uint32_t*>((uintptr_t)this + 0x18); }

		template<typename F>
		void for_each(const F callback)
		{
			for (uint32_t i = 0; i < get_size(); i++) {
				auto object = this->get(i);
				if (!object)
					continue;
				callback(object, i);
			}
		}

		void add(int idx, T value) {
			if (!this || (uintptr_t)this < 0xFFFFFFFF || (uintptr_t)this > 0xF000000000000000) return;
			*reinterpret_cast<T*>(this + (0x20 + (idx * 0x8))) = value;
		}
	};

 }
