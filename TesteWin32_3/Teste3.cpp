// Janela Transparente
//
// Reinaldo Moreira - 2014-12-04

#include "DefaultIncludes.h"

#pragma warning(disable:4189)

LRESULT CALLBACK myProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE, HINSTANCE hInstance, LPSTR, INT nCmdShow)
{
	WNDCLASSEX wndClassEx;

	wndClassEx.cbSize = sizeof(WNDCLASSEX);
	wndClassEx.style = CS_HREDRAW | CS_VREDRAW;
	wndClassEx.lpfnWndProc = myProc;
	wndClassEx.cbClsExtra = (INT)0;
	wndClassEx.cbWndExtra = (INT)0;
	wndClassEx.hInstance = hInstance;
	wndClassEx.hIcon = LoadIcon(NULL, IDI_APPLICATION);  // IDI -> ID. ICON
	wndClassEx.hCursor = LoadCursor(NULL, IDC_ARROW);	  // IDC -> ID. CURSOR					 
	wndClassEx.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(200,200,200));
	wndClassEx.lpszMenuName = NULL;
	wndClassEx.lpszClassName = TEXT("TransparentWindow");
	wndClassEx.hIconSm = LoadIcon(NULL, IDI_WINLOGO);

	InitCommonControls();

	if (!RegisterClassExW(&wndClassEx))
		return FALSE;

	HWND hwnd = CreateWindowExW(
		WS_EX_LAYERED,
		TEXT("TransparentWindow"),
		TEXT("Janelinha levemente transparente!"),
		WS_VISIBLE | WS_OVERLAPPEDWINDOW | WS_VSCROLL,
		CW_USEDEFAULT, CW_USEDEFAULT, 
		CW_USEDEFAULT, CW_USEDEFAULT, 
		NULL, NULL, 
		hInstance, 
		0);



	HWND hwndButton = CreateWindowExW(
		0,
		TEXT("BUTTON"),
		TEXT("OK"),
		WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | BS_FLAT,
		10, 10, 100, 100, hwnd, (HMENU)IDOK, hInstance, NULL);

	HWND hwndButton2 = CreateWindowExW(
		0,
		TEXT("BUTTON"),
		TEXT("SOU MITO PRA CARAIO!"),
		WS_VISIBLE | WS_CHILD | BS_FLAT,
		120, 10, 250, 100, hwnd, (HMENU)IDOK, hInstance, NULL);

	//EnableWindow(hwndButton2, FALSE);

	SetLayeredWindowAttributes(
		hwnd,
		RGB(100, 100, 100),
		200,
		LWA_ALPHA
		);

	ShowWindow(hwnd, nCmdShow);

	UpdateWindow(hwnd);	 // Envia um WM_PAINT

	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK myProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) 
{
	switch (message)
	{
	case WM_CREATE:
		//MessageBox(hwnd, 
		//	TEXT("Oba, fui criada!\n Ainda Serei transparente véi!"), 
		//	TEXT("HELLO WINDOW!"), 
		//	MB_OK);

		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}