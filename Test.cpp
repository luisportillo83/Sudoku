#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "Sudoku.h"
#include "models/Board.h"
#include "models/Cell.h"
#include "models/Region.h"

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

	(new Sudoku())->play();
	return 0;
}
