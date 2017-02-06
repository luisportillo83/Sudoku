#include "NumberChecker.h"

namespace models {

NumberChecker::NumberChecker() {

}

bool NumberChecker::isRowCompleted(unsigned int row) {
	return false;
}

bool NumberChecker::isColumnCompleted(unsigned int column) {
	return false;
}

bool NumberChecker::isRegionCompleted(unsigned int region) {
	return false;
}

bool NumberChecker::hasAllNumbers(std::vector<Cell *> cells) {
	return false;
}

/*
bool Board::isRowCompleted(unsigned int row) {
	std::vector<Cell *> rowToCheck;

	for (unsigned int i = 0; i < Board::NUMBER_OF_ROWS; i++) {
		rowToCheck.push_back(cells.at((row * Board::NUMBER_OF_ROWS) + i));
	}

	return hasAllNumbers(rowToCheck);
}

bool Board::isColumnCompleted(unsigned int column) {
	std::vector<Cell *> columnToCheck;

	for (unsigned int i = 0; i < Board::NUMBER_OF_ROWS; i++) {
		columnToCheck.push_back(cells.at((i * Board::NUMBER_OF_ROWS) + column));
	}
	return hasAllNumbers(columnToCheck);
}

bool Board::isRegionCompleted(unsigned int region) {
	std::vector<Cell *> regionToCheck;

	// TODO Poner un solo FOR dentro de un FOR

	for (unsigned int i = 0; i < sqrt(Board::NUMBER_OF_ROWS); i++) {
		//regionToCheck.push_back(cells.at(i + (???)));
	}

	for (unsigned int i = 0; i < sqrt(Board::NUMBER_OF_ROWS); i++) {
		//regionToCheck.push_back(cells.at(i + (???)));
	}

	for (unsigned int i = 0; i < sqrt(Board::NUMBER_OF_ROWS); i++) {
		// regionToCheck.push_back(cells.at(i + (???)));
	}
	return true;
	// TODO return hasAllNumbers(regionToCheck);
}

bool Board::hasAllNumbers(std::vector<Cell *> cells) {
	assert(cells.size() == Board::NUMBER_OF_ROWS);
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
*/

}
