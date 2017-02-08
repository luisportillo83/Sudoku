#include <cassert>
#include <algorithm>
#include <math.h>
#include "NumberChecker.h"

namespace models {

bool NumberChecker::isRowCompleted(unsigned int row, std::vector<Cell *> cells) {
	assert(row < sqrt(cells.size()));
	std::vector<Cell *> rowToCheck;

	for (unsigned int i = 0; i < sqrt(cells.size()); i++) {
		rowToCheck.push_back(cells.at((row * sqrt(cells.size())) + i));
	}

	return hasAllNumbers(rowToCheck);
}

bool NumberChecker::isColumnCompleted(unsigned int column, std::vector<Cell *> cells) {
	assert(column < sqrt(cells.size()));
	std::vector<Cell *> columnToCheck;

	for (unsigned int i = 0; i < sqrt(cells.size()); i++) {
		columnToCheck.push_back(cells.at((i * sqrt(cells.size())) + column));
	}
	return hasAllNumbers(columnToCheck);
}

bool NumberChecker::hasAllNumbers(std::vector<Cell *> cells) {
	std::vector<unsigned int> cellValues;

	for (unsigned int i = 0; i < cells.size(); i++) {
		if (cells.at(i)->getValue() == Cell::CELL_NO_VALUE) {
			return false;
		}
		cellValues.push_back(cells.at(i)->getValue());
	}

	std::sort(cellValues.begin(), cellValues.end());

	for (unsigned int i = 0; i < cellValues.size(); i++) {
		if (cellValues.at(i) != (i + 1)) {
			return false;
		}
	}
	return true;
}

}
