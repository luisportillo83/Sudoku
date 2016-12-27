#ifndef BOARD_H_
#define BOARD_H_

#include "Region.h"

namespace models {

class Board {
public:
	Board();

	static const unsigned int NUMBER_OF_REGIONS;
private:
	Region * regions;
};

}

#endif
