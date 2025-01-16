#pragma once

#include <Windows.h>
#include <cstdint>
#include "detours.h"

#pragma comment(lib, "detours.lib")

//#include "Singletons.h"


namespace SDK
{
	namespace utils
	{
		namespace h5o5ok5s
		{
			class Hooker
			{
			public:
				Hooker();
				~Hooker();
				void __stdcall HookFunction(PVOID* destination, PVOID source);
				void __stdcall UnhookFunction(PVOID* destination, PVOID source);
				//template <typename T> T __stdcall HookVirtual( void* func, T Hook );
			};
		}
	}
}