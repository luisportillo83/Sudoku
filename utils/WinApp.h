#ifndef UTILS_WINAPP_H_
#define UTILS_WINAPP_H_

#pragma once
#include <windows.h>

namespace utils {

class WinApp {
public:
	WinApp(HINSTANCE hInst, char *ClasName, WNDPROC WndPrc, LPCTSTR MenuName = NULL);
	void registerApp();

protected:
	WNDCLASSEX windowClassEs;
};

}

#endif
