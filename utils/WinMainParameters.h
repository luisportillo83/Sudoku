#ifndef WINMAINPARAMETERS_H_
#define WINMAINPARAMETERS_H_

#include <windows.h>

namespace utils {

class WinMainParameters {
public:
	WinMainParameters(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
	HINSTANCE getCurrentInstance();
	HINSTANCE getPrevInstance();
	LPSTR getCmdLine();
	int getCmdShow();
protected:
	HINSTANCE hInstance;
	HINSTANCE hPrevInstance;
	LPSTR lpCmdLine;
	int nCmdShow;
};

}

#endif
