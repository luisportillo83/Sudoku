#ifndef UTILS_WINMAIN_H_
#define UTILS_WINMAIN_H_

#include <windows.h>
#include "WinMainParameters.h"

#define IDR_MENU1                       101
#define IDI_ICON1                       102
#define ID_FILE_CLEAR                   40001
#define ID_FILE_EXIT                    40002
#define ID_HELP_ABOUT                   40003

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
	WinMain(WinMainParameters * winMainParameters);
	bool registerWindow(WNDPROC windowProc);
	bool createWindow();
	void showWindow();
	void updateWindow();

	static const char CLASS_NAME[];
	static const char WINDOW_TITLE[];
private:
	WinMainParameters * winMainParameters;
	HWND windowHandler;
};

}

#endif

