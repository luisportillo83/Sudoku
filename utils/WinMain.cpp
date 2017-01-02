#include "WinMain.h"

namespace utils {

int WinMain::createWindow(WinMainParameters * winMainParameters) {
	const char g_szClassName[] = "SudokuClass";
	WNDCLASSEX wc;

	wc.cbSize        = sizeof(WNDCLASSEX);
	wc.style         = 0;
	//TODO wc.lpfnWndProc   = WndProc;
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = winMainParameters->getCurrentInstance();
	wc.hIcon         = LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON1));
	wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+2);
	wc.lpszMenuName  = MAKEINTRESOURCE(IDR_MENU1);
	wc.lpszClassName = g_szClassName;
	wc.hIconSm       = LoadIcon(winMainParameters->getCurrentInstance(), MAKEINTRESOURCE(IDI_ICON1));

	if (!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	HWND hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, g_szClassName, "Sudoku", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
			CW_USEDEFAULT, 330, 400,	NULL, NULL, winMainParameters->getCurrentInstance(), NULL);

	if (!hwnd) {
		MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	ShowWindow(hwnd, winMainParameters->getCmdShow());
	UpdateWindow(hwnd);

	MSG Msg;
	while (GetMessage(&Msg, NULL, 0, 0) > 0) {
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}

	return Msg.wParam;
}

}
