#include <cassert>
#include <algorithm>
#include <math.h>
#include "Board.h"

namespace models {

const unsigned int Board::NUMBER_OF_REGIONS = 9;
const unsigned int Board::NUMBER_OF_ROWS = 9;
const unsigned int Board::NUMBER_OF_COLUMNS = 9;
const unsigned int Board::NUMBER_OF_CELLS = Board::NUMBER_OF_ROWS * Board::NUMBER_OF_COLUMNS;

Board::Board() {
	for (unsigned int row = 0; row < Board::NUMBER_OF_ROWS; row++) {
		for (unsigned int column = 0; column < Board::NUMBER_OF_COLUMNS; column++) {
			cells.push_back(new Cell());
		}
	}
}

void Board::setValue(unsigned int row, unsigned int column, unsigned int value) {
	assert(row <= Board::NUMBER_OF_ROWS);
	assert(column <= Board::NUMBER_OF_COLUMNS);
	cells[(row * Board::NUMBER_OF_COLUMNS) + column]->setValue(value);
}

bool Board::isCompleted() {
	for (unsigned int i = 0; i < Board::NUMBER_OF_ROWS; i++) {
		if (!isRowCompleted(i)) {
			return false;
		}
	}

	for (unsigned int i = 0; i < Board::NUMBER_OF_COLUMNS; i++) {
		if (!isColumnCompleted(i)) {
			return false;
		}
	}

	for (unsigned int i = 0; i < Board::NUMBER_OF_REGIONS; i++) {
		if (!isRegionCompleted(i)) {
			return false;
		}
	}

	return true;
}

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
		columnToCheck.push_back(cells.at(column));
	}
	return hasAllNumbers(columnToCheck);
}

bool Board::isRegionCompleted(unsigned int region) {
	// TODO
	// Construir una region y luego llamar a isCompleted() de la region ???
	return true;
}

bool Board::hasAllNumbers(std::vector<Cell *> cells) {
	assert(cells.size() == Board::NUMBER_OF_ROWS);
	for (unsigned int i = 0; i < cells.size(); i++) {
		if (cells.at(i)->getValue() != Cell::CELL_NO_VALUE) {
			return false;
		}
	}
	std::sort(cells.begin(), cells.end());
	for (unsigned int i = 0; i < cells.size(); i++) {
		if (cells.at(i)->getValue() != i) {
			return false;
		}
	}
	return true;
}

}
