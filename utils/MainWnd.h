#ifndef UTILS_MAINWND_H_
#define UTILS_MAINWND_H_

#pragma once
#include <windows.h>

namespace utils {

class MainWnd {
public:
	MainWnd();
	HWND Create(HINSTANCE hinst, LPCTSTR clsname, LPCTSTR wndname, HWND parent   = NULL,
			DWORD dStyle  = WS_OVERLAPPEDWINDOW, DWORD dXStyle = 0L, int x = CW_USEDEFAULT,
			int y = CW_USEDEFAULT, int width = CW_USEDEFAULT, int height = CW_USEDEFAULT);
	bool Show(int dCmdShow = SW_SHOWNORMAL);
	operator HWND();

protected:
	HWND windowHandle;
};

}

#endif
