#include <cassert>
#include <math.h>
#include "Board.h"

namespace models {

const unsigned int Board::NUMBER_OF_REGIONS = 9;
const unsigned int Board::NUMBER_OF_ROWS = 9;
const unsigned int Board::NUMBER_OF_COLUMNS = 9;
const unsigned int Board::NUMBER_OF_CELLS = Board::NUMBER_OF_ROWS * Board::NUMBER_OF_COLUMNS;

Board::Board() {

}

void Board::setValue(unsigned int row, unsigned int column, unsigned int value) {
	assert(row <= Board::NUMBER_OF_ROWS);
	assert(column <= Board::NUMBER_OF_COLUMNS);

	cells[(row * Board::NUMBER_OF_COLUMNS) + column].setValue(value);
}

bool Board::isCompleted() {
	// Check columns
	// Check rows
	// Check regions
	return true;
}



bool Board::isRowCompleted(unsigned int row) {
	// TODO
	return true;
}

bool Board::isColumnCompleted(unsigned int column) {
	// TODO
	return true;
}

bool Board::isRegionCompleted(unsigned int region) {
	// TODO
	// Construir una region y luego llamar a isCompleted() de la region ???
	return true;
}

bool Board::hasAllNumbers(std::vector<Cell> cells) {
	// TODO
	return true;
}

}
