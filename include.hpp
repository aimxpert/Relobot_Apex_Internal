#pragma once
#include "il2cpp_lib.hpp"
#include "vector.hpp"
 

#define DECLARE_MEMBER( type, klass, name ) type & name( ) { SAPPHIRE_FIELD( klass, ##name ) return *reinterpret_cast< type* >( this + name ); }
#include "winternl.h"
#define BASENETSHOW
#define StrA(a) a
#define StrW(a) a


__declspec(noinline) DWORD64 GetModBase(const wchar_t* Name) {
	PPEB_LDR_DATA Ldr = ((PTEB)__readgsqword(FIELD_OFFSET(NT_TIB, Self)))->ProcessEnvironmentBlock->Ldr;
	for (PLIST_ENTRY CurEnt = Ldr->InMemoryOrderModuleList.Flink; CurEnt != &Ldr->InMemoryOrderModuleList; CurEnt = CurEnt->Flink) {
		PLDR_DATA_TABLE_ENTRY pEntry = CONTAINING_RECORD(CurEnt, LDR_DATA_TABLE_ENTRY, InMemoryOrderLinks);
		if (((DWORD64)Name > 1 && !_wcsicmp(Name, pEntry->BaseDllName.Buffer)) ||
			((DWORD64)Name == 1 && pEntry->BaseDllName.Length == 18 && *(DWORD64*)pEntry->BaseDllName.Buffer == 0x6C00640074006E) || !Name)
			return (DWORD64)pEntry->DllBase;
	} return 0;
}

DWORD64 FindPattern(const PBYTE Pattern, const char* Mask, const wchar_t* Module = nullptr)
{
	PBYTE Start = (PBYTE)GetModBase(Module);
	PIMAGE_NT_HEADERS NTHead = (PIMAGE_NT_HEADERS)(Start + ((PIMAGE_DOS_HEADER)Start)->e_lfanew);
	DWORD Len = NTHead->OptionalHeader.SizeOfImage;

	for (PBYTE region_it = Start; region_it < (Start + Len); ++region_it)
	{
		if (*region_it == *Pattern)
		{
			bool found = true;
			const unsigned char* pattern_it = Pattern, * mask_it = (const PBYTE)Mask, * memory_it = region_it;
			for (; *mask_it && (memory_it < (Start + Len)); ++mask_it, ++pattern_it, ++memory_it) {
				if (*mask_it != 'x') continue;
				if (*memory_it != *pattern_it) {
					found = false;
					break;
				}
			}

			if (found)
				return (DWORD64)region_it;
		}
	}

	return 0;
}

typedef HANDLE(__fastcall* CreateSimpleThreadFn)(void*, PVOID, PVOID, unsigned int);
static CreateSimpleThreadFn CST = nullptr;

void CreateThreadSafe(PVOID StartAddr)
{

	CST = (CreateSimpleThreadFn)FindPattern((PBYTE)"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x30", StrA("xxxx?xxxx?xxxx?xxxxx"), StrW(L"tier0_s64.dll"));
	CST(StartAddr, 0, 0, 0);
	//CloseHandle(CST);
}
