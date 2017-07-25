#pragma once

#include <windows.h>
#include <memory>

class Memory
{
public:
	enum _INSTRUCTIONS
	{
		_I_NOP = 0x90,
		_I_CALL = 0xe8,
		_I_JMP = 0xe9,
		_I_JMP_SHORT = 0xeb,
		_I_JE_SHORT = 0x74,
		_I_JNZ_SHORT = 0x75,
		//_I_PUSH = 0x68,
	};

	static void Fill(DWORD dwAddress, unsigned char data, size_t size);
	static void Fill(DWORD dwAddress, char *data, size_t size);

	static DWORD Find(char *signature, size_t len);
	static DWORD Count(char *signature, size_t len);
};
