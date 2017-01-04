#ifndef UTILS_WINAPP_H_
#define UTILS_WINAPP_H_

#pragma once
#include <windows.h>

namespace utils {

class WinAppp {
public:
	WinAppp(HINSTANCE hInst, char *ClasName, WNDPROC WndPrc, LPCTSTR MenuName = NULL);
	void Register();

protected:
	WNDCLASSEX windowClassEs;
};

}

#endif
