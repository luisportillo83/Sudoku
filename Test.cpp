#include <windows.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "Sudoku.h"
#include "models/Board.h"
#include "models/Cell.h"
#include "models/Region.h"

/*
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

	models::Region r;
	r.addCells(v);
	if (r.isCompleted()) {
		std::cout << ":-D" << std::endl;
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
*/
