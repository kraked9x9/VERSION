#include "Memory.h"

void Memory::Fill(DWORD dwAddress, unsigned char data, size_t size)
{
	unsigned long oldDestProt;
	VirtualProtect((LPVOID)dwAddress, size, PAGE_EXECUTE_READWRITE, &oldDestProt);
	FillMemory((void*)dwAddress, size, data);
	VirtualProtect((LPVOID)dwAddress, size, oldDestProt, &oldDestProt);
}

void Memory::Fill(DWORD dwAddress, char* data, size_t size)
{
	for (size_t i = 0; i < size; i++)
		Fill(dwAddress + i, data[i], 1);
}

DWORD Memory::Find(char * signature, size_t len)
{
	for (unsigned long i = 0x401000; i < 0x999999; i++)
	{
		BYTE* m = (BYTE*)i;

		bool bMatches = true;
		for (size_t j = 0; j < len; j++)
		{
			if (((BYTE*)signature)[j] != 0 && m[j] != ((BYTE*)signature)[j])
			{
				bMatches = false;
				break;
			}
		}

		if (bMatches)
			return (DWORD)i;
	}

	return 0;
}

DWORD Memory::Count(char * signature, size_t len)
{
	DWORD ret = 0;
	for (unsigned long i = 0x401000; i < 0x999999; i++)
	{
		BYTE* m = (BYTE*)i;

		bool bMatches = true;
		for (size_t j = 0; j < len; j++)
		{
			if (((BYTE*)signature)[j] != 0 && m[j] != ((BYTE*)signature)[j])
			{
				bMatches = false;
				break;
			}
		}

		if (bMatches)
			ret++;
	}

	return ret;
}
