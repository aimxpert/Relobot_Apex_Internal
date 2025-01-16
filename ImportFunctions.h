#pragma once
#include <windows.h>
#include <Psapi.h>
#include <d3d11.h>
#include <d3dcompiler.h>
#pragma comment(lib, "d3dcompiler")
#include "lazy_importer.hpp"

namespace SDK
{
	namespace utils
	{
		namespace functions
		{
			inline auto stricmp( const char* str1, const char* str2 ) -> int __cdecl
			{
				int v6; // er9
				int v7; // eax

				auto v2 = ( unsigned __int8* )str2;
				auto v3 = ( unsigned __int8* )str1;
				do
				{
					const int v4 = *v3++;
					const int v5 = *v2;
					v6 = v4 + 32;
					if ( static_cast< unsigned int >( v4 - 65 ) > 0x19 )
						v6 = v4;
					v7 = v5 + 32;
					++v2;
					if ( static_cast< unsigned int >( v5 - 65 ) > 0x19 )
						v7 = v5;
				} while ( v6 && v6 == v7 );
				return v6 - v7;
			}

			//static decltype( &MessageBoxA ) MessageBoxA = nullptr;
			//static decltype( &VirtualProtectEx ) VirtualProtectEx = nullptr;
			//static decltype( &GetCurrentProcess ) GetCurrentProcess = nullptr;
			//static decltype( &GetModuleHandleW ) GetModuleHandleW = nullptr;
			//static decltype( &GetModuleHandleA ) GetModuleHandleA = nullptr;
			//static decltype( &Sleep ) Sleep = nullptr;
			//static decltype( &AllocConsole ) AllocConsole = nullptr;
			//static decltype( &CreateThread ) CreateThread = nullptr;
			//static decltype( &K32GetModuleInformation ) K32GetModuleInformation = nullptr;
			//static decltype( &FreeConsole ) FreeConsole = nullptr;
			//static decltype( &FreeLibraryAndExitThread ) FreeLibraryAndExitThread = nullptr;
			////static decltype( &freopen ) freopen = nullptr;
			//static decltype( &GetSystemMetrics ) GetSystemMetrics = nullptr;
			//static decltype( &GetActiveWindow ) GetActiveWindow = nullptr;
			//static decltype( &FindWindowA ) FindWindowA = nullptr;
			//static decltype( &GetClassNameA ) GetClassNameA = nullptr;
			//static decltype( &D3D11CreateDeviceAndSwapChain ) D3D11CreateDeviceAndSwapChain = nullptr;
			//static decltype( &D3DCompile ) D3DCompile = nullptr;
			////static decltype( &__std_exception_destroy ) __std_exception_destroy = nullptr;
			//static decltype( &free ) free = nullptr;
			//static decltype( &malloc ) malloc = nullptr;
		}

		static void __stdcall InitialiseFunctions( )
		{
			//functions::MessageBoxA = LI_FN( MessageBoxA ).get( );
			//functions::VirtualProtectEx = LI_FN( VirtualProtectEx ).get( );
			//functions::GetCurrentProcess = LI_FN( GetCurrentProcess ).get( );
			//functions::GetModuleHandleW = LI_FN( GetModuleHandleW ).get( );
			//functions::GetModuleHandleA = LI_FN( GetModuleHandleA ).get( );
			//functions::Sleep = LI_FN( Sleep ).get( );
			//functions::AllocConsole = LI_FN( AllocConsole ).get( );
			//functions::CreateThread = LI_FN( CreateThread ).get( );
			//functions::K32GetModuleInformation = LI_FN( K32GetModuleInformation ).get( );
			//functions::FreeConsole = LI_FN( FreeConsole ).get( );
			//functions::FreeLibraryAndExitThread = LI_FN( FreeLibraryAndExitThread ).get( );
			////functions::freopen = LI_FN( freopen ).get( );
			//functions::GetSystemMetrics = LI_FN( GetSystemMetrics ).get( );
			//functions::GetActiveWindow = LI_FN( GetActiveWindow ).get( );
			//functions::FindWindowA = LI_FN( FindWindowA ).get( );
			//functions::GetClassNameA = LI_FN( GetClassNameA ).get( );
			//functions::D3D11CreateDeviceAndSwapChain = LI_FN( D3D11CreateDeviceAndSwapChain ).get( );
			//functions::D3DCompile = LI_FN( D3DCompile ).safe( );
			////functions::__std_exception_destroy = LI_FN( __std_exception_destroy ).get( );
			//functions::free = LI_FN( free ).get( );
			//functions::malloc = LI_FN( malloc ).get( );
		}
	}
}