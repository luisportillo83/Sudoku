#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Sudoku.h"

Sudoku::Sudoku() {
	// TODO
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

/*
int main(void) {
	std::srand(unsigned(std::time(0)));
	//(new Sudoku(new views::ConsoleView(), new Logic()))->play();
	(new Sudoku())->play();
	return 0;
}
*/
