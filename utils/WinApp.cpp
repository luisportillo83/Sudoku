#include "WinApp.h"

namespace utils {

WinAppp::WinAppp(HINSTANCE hInst, char *ClsName, WNDPROC WndPrc, LPCTSTR MenuName) {
	windowClassEs.cbSize        = sizeof(WNDCLASSEX);
	windowClassEs.style         = CS_VREDRAW | CS_HREDRAW | CS_DBLCLKS;
	windowClassEs.lpfnWndProc   = WndPrc;
	windowClassEs.cbClsExtra    = 0;
	windowClassEs.cbWndExtra    = 0;
	windowClassEs.hInstance     = hInst;
	windowClassEs.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	windowClassEs.hCursor       = LoadCursor(NULL, IDC_ARROW);
	windowClassEs.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
	windowClassEs.lpszMenuName  = MenuName;
	windowClassEs.lpszClassName = ClsName;
	windowClassEs.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);
}

void WinAppp::Register() {
	RegisterClassEx(&windowClassEs);
}

}
