#include <iostream>
#include <windows.h>
#include <ctime>
#include "Sudoku.h"
#include "views/graphical/GraphicalView.h"

Sudoku::Sudoku(View * view, Logic * logic) {
	this->logic = logic;
	this->view = view;
}

void Sudoku::play() {
	controllers::OperationController * controller;
	do {
		controller = logic->getOperationController();
		if (controller != NULL) {
			std::cout << "Sudoku!" << std::endl;
			controller = NULL;
			//view->interact(controller);
		}
	} while (controller != NULL);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG message;
	std::srand(unsigned(std::time(0)));
	(new Sudoku(new views::GraphicalView(new utils::WinMainParameters(hInstance, hPrevInstance, lpCmdLine, nCmdShow)), new Logic()))->play();
	return message.wParam;
}
