// Simplest Win32
// Reinaldo Moreira - 2014-12-04

#define WIN32_LEAN_AND_MEAN
#define UNICODE

#include <Windows.h>	  // brings windows shit


INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
	LockWorkStation();
}