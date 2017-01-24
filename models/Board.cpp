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
		columnToCheck.push_back(cells.at((i * Board::NUMBER_OF_ROWS) + column));
	}
	return hasAllNumbers(columnToCheck);
}

bool Board::isRegionCompleted(unsigned int region) {
	std::vector<Cell *> regionToCheck;

	for (unsigned int i = 0; i < Board::NUMBER_OF_ROWS; i++) {
		// TODO
		regionToCheck.push_back(cells.at(region));
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
