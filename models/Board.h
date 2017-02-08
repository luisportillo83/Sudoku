#ifndef BOARD_H_
#define BOARD_H_

#include <vector>
#include "NumberChecker.h"
#include "Cell.h"

namespace models {

class Board {
public:
	Board();
	void setValue(unsigned int row, unsigned int column, unsigned int value);
	unsigned int getValue(unsigned int row, unsigned int column);
	bool canPutValue(unsigned int value, unsigned int row, unsigned int column);
	void clearBoard();
	void clearCell(unsigned int row, unsigned int column);
	bool isCompleted();

	static const unsigned int NUMBER_OF_REGIONS;
	static const unsigned int NUMBER_OF_ROWS;
	static const unsigned int NUMBER_OF_COLUMNS;
	static const unsigned int NUMBER_OF_CELLS;

private:
	std::vector<Cell *> cells;
	NumberChecker * numberChecker;

	bool isValueinRow(unsigned int value, unsigned int row);
	bool isValueInColumn(unsigned int value, unsigned int column);
};

}

#endif
