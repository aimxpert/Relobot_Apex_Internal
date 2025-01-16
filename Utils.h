#pragma once

#include "Globals.h"
#include "Classes.hpp"
#include "ImportFunctions.h"
#include "Vector.hpp"
#include <string>
#include <string_view>

#define btoa( x ) ( ( x ) ? "true" : "false" )

namespace SDK
{
	namespace utils
	{
		namespace memory
		{
			bool compare_data(PBYTE pData, PBYTE bSig, char* szMask) {
				for (; *szMask; ++szMask, ++pData, ++bSig) {
					if (*szMask == 'x' && *pData != *bSig)
						return false;
				}
				return (*szMask) == 0;
			}

			PBYTE find_pattern(PBYTE dwAddress, DWORD dwSize, PBYTE pbSig, char* szMask, long offset) {
				size_t length = strlen(szMask);
				for (size_t i = NULL; i < dwSize - length; i++) {
					if (compare_data(dwAddress + i, pbSig, szMask))
						return dwAddress + i + offset;
				}
				return 0;
			}

			//template <class C>
			//C read_mem( DWORD_PTR( Address ), size_t size ) {
			//	C c;
			//	ReadProcessMemory( GetCurrentProcess( ), reinterpret_cast< LPCVOID >( Address ), &c, sizeof( size ), nullptr );
			//	return c;
			//}

			//template<class CharT = char>
			//std::basic_string<CharT> read_chars( std::uintptr_t address, std::size_t max_length = 256 )
			//{
			//	std::basic_string<CharT> str( max_length, CharT( ) );
			//	// I'll assume this throws on failed read.
			//	// If you are using c++17 you can call str.data() instead of &str[0]
			//	read_mem< CharT >( address, sizeof( CharT ) * max_length );
			//	// get the position of null terminator
			//	auto it = str.find( CharT( ) );
			//	// don't want to waste an allocation and will return the existing string to be reused
			//	if ( it == str.npos )
			//		str.clear( );
			//	else
			//		str.resize( it );

			//	return str;
			//}

			//std::uintptr_t resolve_class_by_name( const char* class_name, const char* header_name )
			//{
			//	const auto dos_header = reinterpret_cast< PIMAGE_DOS_HEADER >( variables::game_assembly_base );
			//	const auto nt_headers = reinterpret_cast< PIMAGE_NT_HEADERS >( reinterpret_cast< std::uintptr_t >( dos_header ) + dos_header->e_lfanew );
			//	const auto first_section = IMAGE_FIRST_SECTION( nt_headers );

			//	for ( auto section = first_section; section < first_section + nt_headers->FileHeader.NumberOfSections; section++ )
			//	{
			//		if ( std::strcmp( reinterpret_cast< const char* >( section->Name ), header_name ) )
			//			continue;

			//		std::printf( "[#] section->Name: %s\n", section->Name );
			//		std::printf( "[#] section->Misc.VirtualSize: %u\n", section->Misc.VirtualSize );

			//		for ( std::uintptr_t offset = section->Misc.VirtualSize; offset > 0; offset -= 8 )
			//		{
			//			auto class_ptr =
			//				*reinterpret_cast< std::uintptr_t* >( variables::game_assembly_base + std::uintptr_t( section->VirtualAddress ) + offset );

			//			if ( !class_ptr )
			//				continue;

			//			//char buffer [ 0x1000 ];
			//			//size_t bytes_copied{};
			//			//ReadProcessMemory( GetCurrentProcess( ), reinterpret_cast< LPVOID >( class_ptr + 0x10 ), &buffer, sizeof( buffer ), &bytes_copied );

			//			auto buffer = read_chars( class_ptr + 0x10 );

			//			//std::printf( "[#] buffer: %s\n", buffer );

			//			if ( !std::strcmp( buffer.c_str( ), class_name ) )
			//			{
			//				std::printf( "[#] Found! 0x%x n", section->VirtualAddress + offset );
			//				return class_ptr;
			//			}
			//		}
			//	}

			//	std::printf( "[#] Couldn't Find %s\n", class_name );
			//	//std::this_thread::sleep_for( std::chrono::seconds( 5 ) );
			//	return std::uintptr_t( );
			//}

			inline int strcmp_(const char* s1, const char* s2) {
				unsigned char c1, c2;
				while ((c1 = *s1++) == (c2 = *s2++)) {
					if (c1 == '\0')
						return 0;
				}
				return c1 - c2;
			}

			inline auto get_imported_function(const uintptr_t mod, const char* name) -> PIMAGE_THUNK_DATA64
			{
				const auto dos_header = reinterpret_cast<PIMAGE_DOS_HEADER>(mod);
				const auto nt_headers = reinterpret_cast<PIMAGE_NT_HEADERS>(reinterpret_cast<uintptr_t>(dos_header) + dos_header->e_lfanew);

				const auto data_directory = nt_headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
				auto import_descriptor = reinterpret_cast<PIMAGE_IMPORT_DESCRIPTOR>(mod + data_directory.VirtualAddress);

				if (!import_descriptor) return{};

				for (; import_descriptor->Characteristics; import_descriptor++)
				{
					auto org_thunk = import_descriptor->OriginalFirstThunk
						? (PIMAGE_THUNK_DATA64)(mod + import_descriptor->OriginalFirstThunk)
						: (PIMAGE_THUNK_DATA64)(mod + import_descriptor->FirstThunk);

					if (!org_thunk) continue;

					//auto lib_name = ( char* )( mod + import_descriptor->Name );

					auto first_thunk = (PIMAGE_THUNK_DATA64)(mod + import_descriptor->FirstThunk);

					if (!first_thunk) continue;

					for (; org_thunk->u1.AddressOfData; org_thunk++, first_thunk++)
					{
						auto function_name = org_thunk->u1.Ordinal & IMAGE_ORDINAL_FLAG64
							? (char*)(mod + org_thunk->u1.Ordinal & 0xFFFF)
							: (char*)((PIMAGE_IMPORT_BY_NAME)(mod + org_thunk->u1.AddressOfData))->Name;

						if (!function_name) continue;

						if (!strcmp_(function_name, name))
						{
							return first_thunk/*->u1.AddressOfData*/;
						}
					}
				}

				return 0;
			}

		}

		namespace Iat_hook
		{
			void** find(const char* function, HMODULE module)
			{
				if (!module)
					module = GetModuleHandle(0);

				PIMAGE_DOS_HEADER img_dos_headers = (PIMAGE_DOS_HEADER)module;
				PIMAGE_NT_HEADERS img_nt_headers = (PIMAGE_NT_HEADERS)((byte*)img_dos_headers + img_dos_headers->e_lfanew);
				PIMAGE_IMPORT_DESCRIPTOR img_import_desc = (PIMAGE_IMPORT_DESCRIPTOR)((byte*)img_dos_headers + img_nt_headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);
				if (img_dos_headers->e_magic != IMAGE_DOS_SIGNATURE)
					return nullptr;

				for (IMAGE_IMPORT_DESCRIPTOR* iid = img_import_desc; iid->Name != 0; iid++) {
					for (int func_idx = 0; *(func_idx + (void**)(iid->FirstThunk + (size_t)module)) != nullptr; func_idx++) {
						char* mod_func_name = (char*)(*(func_idx + (size_t*)(iid->OriginalFirstThunk + (size_t)module)) + (size_t)module + 2);
						const intptr_t nmod_func_name = (intptr_t)mod_func_name;
						if (nmod_func_name >= 0) {
							if (!::strcmp(function, mod_func_name))
								return func_idx + (void**)(iid->FirstThunk + (size_t)module);
						}
					}
				}

				return 0;

			}

			uintptr_t detour_iat_ptr(const char* function, void* newfunction, HMODULE module = 0)
			{
				auto&& func_ptr = find(function, module);
				if (*func_ptr == newfunction || *func_ptr == nullptr)
					return 0;

				DWORD old_rights, new_rights = PAGE_READWRITE;
				VirtualProtect(func_ptr, sizeof(uintptr_t), new_rights, &old_rights);
				uintptr_t ret = (uintptr_t)*func_ptr;
				*func_ptr = newfunction;
				VirtualProtect(func_ptr, sizeof(uintptr_t), old_rights, &new_rights);
				return ret;
			}
		};

		namespace maths
		{
			constexpr auto r2d = 57.2957795131f; /* 180 / pi, used for conversion from radians to degrees */
			constexpr auto d2r = 0.01745329251f; /* pi / 180, used for conversion from degrees to radians */

			__forceinline vec3_t calculate_angle(vec3_t source, vec3_t destination)
			{
				const auto direction = source - destination;

				return { std::asin(direction.y / direction.length()) * r2d, -std::atan2(direction.x, -direction.z) * r2d, 0.f };
			}
 

			__forceinline float screen_distance_from_center__(vec2_t Position)
			{
				return sqrt(pow(abs(Position.x - (variables::game_screen_X / 2)), 2) + pow(abs(Position.y - (variables::game_screen_Y / 2)), 2));
			}
		}

		namespace rendering
		{
 
			maths::vector3 transform_to_3dposition(uintptr_t pTransform)
			{
				if (!pTransform) {
					return maths::vector3();
				}

				__m128 result;

				const __m128 mulVec0 = { -2.000, 2.000, -2.000, 0.000 };
				const __m128 mulVec1 = { 2.000, -2.000, -2.000, 0.000 };
				const __m128 mulVec2 = { -2.000, -2.000, 2.000, 0.000 };

				maths::TransformAccessReadOnly pTransformAccessReadOnly = *(maths::TransformAccessReadOnly*)((uintptr_t)pTransform + 0x38);

				unsigned int index = *(unsigned int*)((uintptr_t)pTransform + 0x40);
				maths::TransformData transformData = *(maths::TransformData*)((uintptr_t)pTransformAccessReadOnly.pTransformData + 0x18);

				if (transformData.pTransformArray && transformData.pTransformIndices)
				{
					result = *(__m128*)((ULONGLONG)transformData.pTransformArray + 0x30 * index);
					int transformIndex = *(int*)((ULONGLONG)transformData.pTransformIndices + 0x4 * index);
					int pSafe = 0;
					while (transformIndex >= 0 && pSafe++ < 200)
					{
						maths::Matrix34 matrix34 = *(maths::Matrix34*)((ULONGLONG)transformData.pTransformArray + 0x30 * transformIndex);

						__m128 xxxx = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0x00));	// xxxx
						__m128 yyyy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0x55));	// yyyy
						__m128 zwxy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0x8E));	// zwxy
						__m128 wzyw = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0xDB));	// wzyw
						__m128 zzzz = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0xAA));	// zzzz
						__m128 yxwy = _mm_castsi128_ps(_mm_shuffle_epi32(*(__m128i*)(&matrix34.vec1), 0x71));	// yxwy
						__m128 tmp7 = _mm_mul_ps(*(__m128*)(&matrix34.vec2), result);

						result = _mm_add_ps(
							_mm_add_ps(
								_mm_add_ps(
									_mm_mul_ps(
										_mm_sub_ps(
											_mm_mul_ps(_mm_mul_ps(xxxx, mulVec1), zwxy),
											_mm_mul_ps(_mm_mul_ps(yyyy, mulVec2), wzyw)),
										_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0xAA))),
									_mm_mul_ps(
										_mm_sub_ps(
											_mm_mul_ps(_mm_mul_ps(zzzz, mulVec2), wzyw),
											_mm_mul_ps(_mm_mul_ps(xxxx, mulVec0), yxwy)),
										_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0x55)))),
								_mm_add_ps(
									_mm_mul_ps(
										_mm_sub_ps(
											_mm_mul_ps(_mm_mul_ps(yyyy, mulVec0), yxwy),
											_mm_mul_ps(_mm_mul_ps(zzzz, mulVec1), zwxy)),
										_mm_castsi128_ps(_mm_shuffle_epi32(_mm_castps_si128(tmp7), 0x00))),
									tmp7)), *(__m128*)(&matrix34.vec0));

						transformIndex = *(int*)((ULONGLONG)transformData.pTransformIndices + 0x4 * transformIndex);
					}
				}

				return maths::vector3(result.m128_f32[0], result.m128_f32[1], result.m128_f32[2]);
			}
		}
	}
}