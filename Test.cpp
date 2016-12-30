#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Sudoku.h"
#include "models/Board.h"
#include "models/Cell.h"

int main(void) {
	std::srand(unsigned(std::time(0)));

	models::Cell c;
	c.setValue(5);
	std::cout << c.getValue() << std::endl;

	models::Board b;
	b.setValue(3, 3, 8);
	if (!b.isCompleted()) {
		std::cout << ":-)" << std::endl;
	}

	(new Sudoku())->play();
	return 0;
}
