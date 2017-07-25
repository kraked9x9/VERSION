#include <string>

#include "Exports.h"

FARPROC Exports::p[];
volatile unsigned long Exports::_p;

void Exports::Initialize()
{
	wchar_t *_system = new wchar_t[MAX_PATH];
	GetSystemDirectoryW(_system, MAX_PATH);
	std::wstring _syspath = _system;
	delete _system;
	_syspath += L"\\version.dll";
	HINSTANCE hL = LoadLibraryW(_syspath.c_str());

	p[0] = GetProcAddress(hL, "GetFileVersionInfoA");
	p[1] = GetProcAddress(hL, "GetFileVersionInfoByHandle");
	p[2] = GetProcAddress(hL, "GetFileVersionInfoExW");
	p[3] = GetProcAddress(hL, "GetFileVersionInfoSizeA");
	p[4] = GetProcAddress(hL, "GetFileVersionInfoExW");
	p[5] = GetProcAddress(hL, "GetFileVersionInfoSizeW");
	p[6] = GetProcAddress(hL, "GetFileVersionInfoW");
	p[7] = GetProcAddress(hL, "VerFindFileA");
	p[8] = GetProcAddress(hL, "VerFindFileW");
	p[9] = GetProcAddress(hL, "VerInstallFileA");
	p[10] = GetProcAddress(hL, "VerInstallFileW");
	p[11] = GetProcAddress(hL, "VerLanguageNameA");
	p[12] = GetProcAddress(hL, "VerLanguageNameW");
	p[13] = GetProcAddress(hL, "VerQueryValueA");
	p[14] = GetProcAddress(hL, "VerQueryValueW");
}

extern "C" __declspec(naked) void __stdcall __E__0__()  { Exports::_p = (unsigned long)Exports::p[0]; __asm jmp Exports::_p }
extern "C" __declspec(naked) void __stdcall __E__1__()  { Exports::_p = (unsigned long)Exports::p[1]; __asm jmp Exports::_p }
extern "C" __declspec(naked) void __stdcall __E__2__()  { Exports::_p = (unsigned long)Exports::p[2]; __asm jmp Exports::_p }
extern "C" __declspec(naked) void __stdcall __E__3__()  { Exports::_p = (unsigned long)Exports::p[3]; __asm jmp Exports::_p }
extern "C" __declspec(naked) void __stdcall __E__4__()  { Exports::_p = (unsigned long)Exports::p[4]; __asm jmp Exports::_p }
extern "C" __declspec(naked) void __stdcall __E__5__()  { Exports::_p = (unsigned long)Exports::p[5]; __asm jmp Exports::_p }
extern "C" __declspec(naked) void __stdcall __E__6__()  { Exports::_p = (unsigned long)Exports::p[6]; __asm jmp Exports::_p }
extern "C" __declspec(naked) void __stdcall __E__7__()  { Exports::_p = (unsigned long)Exports::p[7]; __asm jmp Exports::_p }
extern "C" __declspec(naked) void __stdcall __E__8__()  { Exports::_p = (unsigned long)Exports::p[8]; __asm jmp Exports::_p }
extern "C" __declspec(naked) void __stdcall __E__9__()  { Exports::_p = (unsigned long)Exports::p[9]; __asm jmp Exports::_p }
extern "C" __declspec(naked) void __stdcall __E__10__() { Exports::_p = (unsigned long)Exports::p[10]; __asm jmp Exports::_p }
extern "C" __declspec(naked) void __stdcall __E__11__() { Exports::_p = (unsigned long)Exports::p[11]; __asm jmp Exports::_p }
extern "C" __declspec(naked) void __stdcall __E__12__() { Exports::_p = (unsigned long)Exports::p[12]; __asm jmp Exports::_p }
extern "C" __declspec(naked) void __stdcall __E__13__() { Exports::_p = (unsigned long)Exports::p[13]; __asm jmp Exports::_p }
extern "C" __declspec(naked) void __stdcall __E__14__() { Exports::_p = (unsigned long)Exports::p[14]; __asm jmp Exports::_p }
