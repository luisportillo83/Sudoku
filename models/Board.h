#ifndef BOARD_H_
#define BOARD_H_

#include "Region.h"
#include "Cell.h"

namespace models {

class Board {
public:
	Board();
	void setValue(unsigned int row, unsigned int column, unsigned int value);
	bool isCompleted();

	static const unsigned int NUMBER_OF_REGIONS;
	static const unsigned int NUMBER_OF_ROWS;
	static const unsigned int NUMBER_OF_COLUMNS;
	static const unsigned int NUMBER_OF_CELLS;

private:
	// TODO - Is this needed? - Region * regions;
	std::vector<Cell> cells;

	bool isRowCompleted(unsigned int row);
	bool isColumnCompleted(unsigned int column);
	bool isRegionCompleted(unsigned int region);

	// TODO Move this to util?
	bool hasAllNumbers(std::vector<Cell> cells);
};

}

#endif
