#include "MainWnd.h"

namespace utils {

MainWnd::MainWnd() {
	windowHandle = NULL;
}

HWND MainWnd::Create(HINSTANCE hinst, LPCTSTR clsname, LPCTSTR wndname, HWND parent,
		DWORD dStyle, DWORD dXStyle, int x, int y, int width, int height) {
	windowHandle = CreateWindowEx(dXStyle, clsname, wndname, dStyle, x, y, width, height,
			parent, NULL, hinst, NULL);
	return windowHandle;
}

bool MainWnd::Show(int dCmdShow) {
	return (ShowWindow(windowHandle, dCmdShow) && UpdateWindow(windowHandle));
}

bool MainWnd::getMessage(MSG * Msg) {
	return GetMessage(Msg, NULL, 0, 0);
}

void MainWnd::translateAndDispatchMessage(MSG * Msg) {
	TranslateMessage(Msg);
	DispatchMessage(Msg);
}

MainWnd::operator HWND() {
	return windowHandle;
}

}
