#ifndef UTILS_WINMAIN_H_
#define UTILS_WINMAIN_H_

#include <windows.h>
#include "WinMainParameters.h"

#define IDR_MENU1                       101
#define IDI_ICON1                       102
#define ID_FILE_CLEAR                   40001
#define ID_FILE_EXIT                    40002
#define ID_HELP_ABOUT                   40003

#define hE1 123
#define hS 124

#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS
#define _APS_NEXT_RESOURCE_VALUE        103
#define _APS_NEXT_COMMAND_VALUE         40004
#define _APS_NEXT_CONTROL_VALUE         1001
#define _APS_NEXT_SYMED_VALUE           101
#endif
#endif

namespace utils {

class WinMain {
public:
	static WinMain* instance();
	bool registerWindow(WinMainParameters * winMainParameters, WNDPROC windowProc);
	bool createWindow();
	void showWindow();
	void updateWindow();
	LRESULT CALLBACK WndProc1(HWND windowHandler, UINT msg, WPARAM wParam, LPARAM lParam);
	WNDPROC WndProc2(HWND windowHandler, UINT msg, WPARAM wParam, LPARAM lParam);
	LRESULT WndProc3(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK WndProc4(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	static const char CLASS_NAME[];
	static const char WINDOW_TITLE[];
private:
	WinMain();
	static WinMain* winMain;
	WinMainParameters * winMainParameters;
	HWND windowHandler;
};

}

#endif

