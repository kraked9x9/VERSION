#define _CRT_SECURE_NO_WARNINGS

#include "Exports.h"
#include "Memory.h"

unsigned long __stdcall DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:

		Exports::Initialize();

		AllocConsole();

		freopen("CONIN$", "r", stdin);
		freopen("CONOUT$", "w", stdout);
		freopen("CONOUT$", "w", stderr);

		/* 7 7 17
		Memory::Fill(0x6068EE, 0x90, 5);  // Decode OnRecv nop
		Memory::Fill(0x6066C5, 0x90, 5);  // Encode WritePacketAutoCrc
		Memory::Fill(0x6062C3, 0x90, 5);  // Encode WritePacket2
		Memory::Fill(0x60679D, 0x90, 5);  // Encode WritePacket
		Memory::Fill(0x463FAD, 0xFF, 2);  // Launcher fix WinProc case 0x113 -> case 0xFFFF
		Memory::Fill(0x788175, 0x90, 6);  // KalOnline0.exe file exist check bypass
		*/

		char *szDecodeOnRecvPattern = "\x50" "\x00" "\x00" "\x00" "\x00" "\x00" "\x8B" "\x4D" "\x08" "\x83" "\xC1" "\x03";
		DWORD dwDecodeOnRecvAddress = Memory::Find(szDecodeOnRecvPattern, 12) + 1;
		DWORD dwDecodeOnRecvCount = Memory::Count(szDecodeOnRecvPattern, 12);

		char *szEncodeWritePacketAutoCrcPattern = "\x48" "\xFF" "\xFF" "\xFF" "\x52" "\x00" "\x00" "\x00" "\x00" "\x00" "\xC7" "\x45" "\xF0";
		DWORD dwEncodeWritePacketAutoCrcAddress = Memory::Find(szEncodeWritePacketAutoCrcPattern, 13) + 5;
		DWORD dwEncodeWritePacketAutoCrcCount = Memory::Count(szEncodeWritePacketAutoCrcPattern, 13);

		char *szEncodeWritePacket2Pattern = "\x4C" "\xFF" "\xFF" "\xFF" "\x52" "\x00" "\x00" "\x00" "\x00" "\x00" "\xC7" "\x45" "\xF0";
		DWORD dwEncodeWritePacket2Address = Memory::Find(szEncodeWritePacket2Pattern, 13) + 5;
		DWORD dwEncodeWritePacket2Count = Memory::Count(szEncodeWritePacket2Pattern, 13);

		char *szEncodeWritePacketPattern = "\x8B" "\x55" "\xEC" "\x52" "\x00" "\x00" "\x00" "\x00" "\x00" "\xC7" "\x45" "\xF0";
		DWORD dwEncodeWritePacketAddress = Memory::Find(szEncodeWritePacketPattern, 12) + 4;
		DWORD dwEncodeWritePacketCount = Memory::Count(szEncodeWritePacketPattern, 12);

		char *szWinProcCase0x113Pattern = "\x81" "\x7D" "\xCC" "\x13" "\x01";
		DWORD dwWinProcCase0x113Address = Memory::Find(szWinProcCase0x113Pattern, 5) + 3;
		DWORD dwWinProcCase0x113Count = Memory::Count(szWinProcCase0x113Pattern, 5);

		char *szKalOnline0FileExistsBypassPattern = "\x83" "\xF8" "\xFF" "\x00" "\x00" "\x00" "\x00" "\x00" "\x00" "\x6A" "\x30";
		DWORD dwKalOnline0FileExistsBypassAddress = Memory::Find(szKalOnline0FileExistsBypassPattern, 11) - 6;
		DWORD dwKalOnline0FileExistsBypassCount = Memory::Count(szKalOnline0FileExistsBypassPattern, 11);

		printf("DecodeOnRecv(%d): \t\t\t0x%06X\n", dwDecodeOnRecvCount, dwDecodeOnRecvAddress);
		printf("EncodeWritePacketAutoCrc(%d): \t\t0x%06X\n", dwEncodeWritePacketAutoCrcCount, dwEncodeWritePacketAutoCrcAddress);
		printf("EncodeWritePacket2(%d): \t\t\t0x%06X\n", dwEncodeWritePacket2Count, dwEncodeWritePacket2Address);
		printf("EncodeWritePacket(%d): \t\t\t0x%06X\n", dwEncodeWritePacketCount, dwEncodeWritePacketAddress);
		printf("WinProcCase0x113(%d): \t\t\t0x%06X\n", dwWinProcCase0x113Count, dwWinProcCase0x113Address);
		printf("KalOnline0FileExistsBypass(%d): \t\t0x%06X\n", dwKalOnline0FileExistsBypassCount, dwKalOnline0FileExistsBypassAddress);

		/* 7 20 17 */
		//Memory::Fill(0x60870E, 0x90, 5);
		Memory::Fill(dwDecodeOnRecvAddress, 0x90, 5);
		//Memory::Fill(0x6084E5, 0x90, 5);
		Memory::Fill(dwEncodeWritePacketAutoCrcAddress, 0x90, 5);
		//Memory::Fill(0x6080E3, 0x90, 5);
		Memory::Fill(dwEncodeWritePacket2Address, 0x90, 5);
		//Memory::Fill(0x6085BD, 0x90, 5);
		Memory::Fill(dwEncodeWritePacketAddress, 0x90, 5);
		//Memory::Fill(0x4644BD, 0xFF, 2);
		Memory::Fill(dwWinProcCase0x113Address, 0xFF, 2);
		//Memory::Fill(0x07886B5, 0x90, 6);
		Memory::Fill(dwKalOnline0FileExistsBypassAddress, 0x90, 6);

		printf("Initialized.\n");

		break;
	}
	return 1;
}
