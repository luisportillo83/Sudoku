#include <windows.h>
#include "utils/WinApp.h"
#include "utils/MainWnd.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "Sudoku.h"
#include "models/Board.h"
#include "models/Cell.h"

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMainxx(HINSTANCE hInstance, HINSTANCE hPrevInst,
				   LPSTR lpCmdLine, int nCmdShow)
{
	MSG   Msg;
	char ClsName[] = "SudokuClass";
	LPCTSTR WndName = "Object-Oriented Win32 Programming";

	// Initialize the application class
	utils::WinAppp WinApp(hInstance, ClsName, MainWndProc);
	WinApp.Register();

	// Create the main window
	utils::MainWnd Wnd;
	Wnd.Create(hInstance, ClsName, WndName);
	// Display the main winow
	Wnd.Show();

	// Process the main window's messages
	while(GetMessage(&Msg, NULL, 0, 0)) {
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}

	return 0;
}
//---------------------------------------------------------------------------
LRESULT CALLBACK MainWndProc(HWND hWnd, UINT Msg,
                             WPARAM wParam, LPARAM lParam)
{
	switch(Msg)
	{
	case WM_DESTROY:
		PostQuitMessage(WM_QUIT);
		return 0;
	}

	return DefWindowProc(hWnd, Msg, wParam, lParam);
}


int mainXXX(void) {
	std::srand(unsigned(std::time(0)));

	models::Cell c;
	c.setValue(5);
	std::cout << c.getValue() << std::endl;

	models::Board b;
	b.setValue(3, 3, 8);
	if (!b.isCompleted()) {
		std::cout << ":-)" << std::endl;
	}

	std::vector<models::Cell *> v;
	for (int i = 1; i <= models::Cell::CELL_MAX_VALUE; i++) {
		c.setValue(i);
		v.push_back(&c);
	}

	return 0;
}

#define IDR_MENU1                       101
#define IDI_ICON1                       102
#define ID_FILE_CLEAR                   40001
#define ID_FILE_EXIT                    40002
#define ID_HELP_ABOUT                   40003

const char g_szClassName[] = "SudokuClass";

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMainXXX(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;
	//InitCommonControls();

	wc.cbSize        = sizeof(WNDCLASSEX);
	wc.style         = 0;
	wc.lpfnWndProc   = WndProc;
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = hInstance;
	wc.hIcon         = LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON1));//IDI_APPLICATION);
	wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+2);
	wc.lpszMenuName  = MAKEINTRESOURCE(IDR_MENU1);//NULL;
	wc.lpszClassName = g_szClassName;
	wc.hIconSm       = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));//IDI_APPLICATION);

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Window Registration Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		g_szClassName,
		"Sudoku",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 330, 400,
		NULL, NULL, hInstance, NULL);

	if (hwnd == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while(GetMessage(&Msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}

