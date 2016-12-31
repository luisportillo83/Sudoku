#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Sudoku.h"
#include "views/graphical/GraphicalView.h"


Sudoku::Sudoku(View * view, Logic * logic) {
	this->logic = logic;
	this->view = view;
}

void Sudoku::play() {
	/*
	controllers::OperationController * controller;
	do {
		controller = logic->getOperationController();
		if (controller != NULL) {
			view->interact(controller);
		}
	} while (controller != NULL);
	*/
	std::cout << "Sudoku!" << std::endl;
}

int main(void) {
	std::srand(unsigned(std::time(0)));
	(new Sudoku(new views::GraphicalView(), new Logic()))->play();
	return 0;
}
