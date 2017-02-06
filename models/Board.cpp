#include <cassert>
#include <algorithm>
#include <math.h>
#include <iostream>
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
	numberChecker = new NumberChecker();
}

void Board::setValue(unsigned int row, unsigned int column, unsigned int value) {
	assert(row <= Board::NUMBER_OF_ROWS);
	assert(column <= Board::NUMBER_OF_COLUMNS);
	cells[(row * Board::NUMBER_OF_COLUMNS) + column]->setValue(value);
}

void Board::clearCell(unsigned int row, unsigned int column) {
	setValue(row, column, models::Cell::CELL_NO_VALUE);
}

void Board::clearBoard() {
	for (unsigned int row = 0; row < Board::NUMBER_OF_ROWS; row++) {
		for (unsigned int column = 0; column < Board::NUMBER_OF_COLUMNS; column++) {
			clearCell(row, column);
		}
	}
}

bool Board::canPutValue(unsigned int value, unsigned int row, unsigned int column) {
	return (!isValueInColumn(value, column) &&
			(!isValueinRow(value, row) &&
			(!isValueInRegion(value, row, column))));
}

unsigned int Board::getValue(unsigned int row, unsigned int column) {
	assert(row <= Board::NUMBER_OF_ROWS);
	assert(column <= Board::NUMBER_OF_COLUMNS);
	return cells[(row * Board::NUMBER_OF_COLUMNS) + column]->getValue();
}

bool Board::isCompleted() {
	for (unsigned int i = 0; i < Board::NUMBER_OF_ROWS; i++) {
		if (!numberChecker->isRowCompleted(i)) {
			return false;
		}
	}
	for (unsigned int i = 0; i < Board::NUMBER_OF_COLUMNS; i++) {
		if (!numberChecker->isColumnCompleted(i)) {
			return false;
		}
	}
	for (unsigned int i = 0; i < Board::NUMBER_OF_REGIONS; i++) {
		if (!numberChecker->isRegionCompleted(i)) {
			return false;
		}
	}
	return true;
}

bool Board::isValueinRow(unsigned int value, unsigned int row) {
	for (unsigned int i = 0; i < Board::NUMBER_OF_COLUMNS; i++) {
		if (cells.at((row * Board::NUMBER_OF_COLUMNS) + i)->getValue() == value) {
			return true;
		}
	}
	return false;
}

bool Board::isValueInColumn(unsigned int value, unsigned int column) {
	for (unsigned int i = 0; i < Board::NUMBER_OF_ROWS; i++) {
		if (cells.at((i * Board::NUMBER_OF_ROWS) + column)->getValue() == value) {
			return true;
		}
	}
	return false;
}

bool Board::isValueInRegion(unsigned int value, unsigned int row, unsigned int column) {
	// TODO
	return false;
}

}
