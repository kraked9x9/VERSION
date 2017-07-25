#pragma once

#include <windows.h>

class Exports
{

public:
	static FARPROC p[15 * 4];
	static volatile unsigned long _p;

	static void Initialize();
};
