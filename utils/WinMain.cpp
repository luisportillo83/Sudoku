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

bool WinMain::registerWindow(WinMainParameters * winMainParameters, WNDPROC windowProc) {
	WNDCLASSEX windowClass;

	windowClass.cbSize        = sizeof(WNDCLASSEX);
	windowClass.style         = 0;
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
