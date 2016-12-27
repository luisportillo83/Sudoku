#ifndef REGION_H_
#define REGION_H_

#include "Cell.h"

namespace models {

class Region {
public:
	Region();

	static const unsigned int NUMBER_OF_CELLS;
protected:
	Cell * cells;
};

}

#endif
