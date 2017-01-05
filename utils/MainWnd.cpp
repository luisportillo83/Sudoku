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

MainWnd::operator HWND() {
	return windowHandle;
}

}
