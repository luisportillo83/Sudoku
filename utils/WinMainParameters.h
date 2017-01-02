#ifndef WINMAINPARAMETERS_H_
#define WINMAINPARAMETERS_H_

#include <windows.h>

namespace util {

class WinMainParameters {
public:
	WinMainParameters(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
};

}

#endif
