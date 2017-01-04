#include "MainWnd.h"

namespace utils {

MainWnd::MainWnd() {
	windowHandle = NULL;
}

HWND MainWnd::Create(HINSTANCE hinst, LPCTSTR clsname, LPCTSTR wndname, HWND parent,
		DWORD dStyle, DWORD dXStyle, int x, int y, int width, int height) {
	windowHandle = CreateWindowEx(dXStyle, clsname, wndname, dStyle, x, y, width, height,
			parent, NULL, hinst, NULL);

	if(windowHandle != NULL) {
		return windowHandle;
	}
	return NULL;
}

BOOL MainWnd::Show(int dCmdShow) {
	if(ShowWindow(windowHandle, dCmdShow) && UpdateWindow(windowHandle)) {
		return TRUE;
	}
	return FALSE;
}

MainWnd::operator HWND() {
	return windowHandle;
}

}
