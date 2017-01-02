#include "../utils/WinMainParameters.h"

namespace utils {

WinMainParameters::WinMainParameters(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	this->hInstance = hInstance;
	this->hPrevInstance = hPrevInstance;
	this->lpCmdLine = lpCmdLine;
	this->nCmdShow = nCmdShow;
}

HINSTANCE WinMainParameters::getCurrentInstance() {
	return hInstance;
}

HINSTANCE WinMainParameters::getPrevInstance() {
	return hPrevInstance;
}

LPSTR WinMainParameters::getCmdLine() {
	return lpCmdLine;
}

int WinMainParameters::getCmdShow() {
	return nCmdShow;
}

}
