#pragma once
#define WIN32_LEAN_AND_MEAN
#define STRICT
#define UNICODE

#include <Windows.h>	  // brings windows shit
#include <CommCtrl.h>
#include <dwmapi.h>


#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")