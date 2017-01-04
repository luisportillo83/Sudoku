#include "WinMain.h"

namespace utils {

const char WinMain::CLASS_NAME[] = "SudokuClass";
const char WinMain::WINDOW_TITLE[] = "Sukodu";

WinMain * WinMain::winMain;

WinMain::WinMain() {

}

WinMain * WinMain::instance() {
	if (WinMain::winMain == NULL) {
		WinMain::winMain = new WinMain();
	}
	return WinMain::winMain;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch(msg)
	{
	case WM_CREATE:
		//initializeControls(hwnd);
		break;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case hS:
			//startSolver();
			break;
		case ID_HELP_ABOUT:
			MessageBox(hwnd,"Sudoku Solver\nby Teodor Merodiyski (c) 2013\n","About",MB_OK);
			break;
		case ID_FILE_CLEAR:
			//clearCells();
			break;
		case ID_FILE_EXIT:
			exit(0);
			break;
		}
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

LRESULT CALLBACK WinMain::WndProc4(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	return 1;
}

bool WinMain::registerWindow(WinMainParameters * winMainParameters, WNDPROC windowProc) {
	WNDCLASSEX windowClass;

	windowClass.cbSize        = sizeof(WNDCLASSEX);
	windowClass.style         = 0;
	//windowClass.lpfnWndProc   = WinMain::WndProc4;
	windowClass.lpfnWndProc   = windowProc;
	windowClass.cbClsExtra    = 0;
	windowClass.cbWndExtra    = 0;
	windowClass.hInstance     = winMainParameters->getCurrentInstance();
	windowClass.hIcon         = LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON1));
	windowClass.hCursor       = LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
	windowClass.lpszMenuName  = MAKEINTRESOURCE(IDR_MENU1);
	windowClass.lpszClassName = WinMain::CLASS_NAME;
	windowClass.hIconSm       = LoadIcon(winMainParameters->getCurrentInstance(), MAKEINTRESOURCE(IDI_ICON1));

	if (!RegisterClassEx(&windowClass)) {
		MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
		return false;
	}
	return true;
}

bool WinMain::createWindow() {
	windowHandler = CreateWindowEx(WS_EX_CLIENTEDGE, WinMain::CLASS_NAME, WinMain::WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, 330, 400,	NULL, NULL, winMainParameters->getCurrentInstance(), NULL);

	if (!windowHandler) {
		MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
		return false;
	}
	return true;
}

void WinMain::showWindow() {
	ShowWindow(windowHandler, winMainParameters->getCmdShow());
}

void WinMain::updateWindow() {
	UpdateWindow(windowHandler);
}

/* TODO
	MSG Msg;
	while (GetMessage(&Msg, NULL, 0, 0) > 0) {
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
*/

}
