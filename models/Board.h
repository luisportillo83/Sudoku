#ifndef BOARD_H_
#define BOARD_H_

#include "Region.h"
#include "Cell.h"

namespace models {

class Board {
public:
	Board();

	static const unsigned int NUMBER_OF_REGIONS;
	static const unsigned int NUMBER_OF_CELLS;
private:
	// TODO - Is this needed? - Region * regions;
	Cell * cells;
};

}

#endif
