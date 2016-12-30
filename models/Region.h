#ifndef REGION_H_
#define REGION_H_

#include <vector>
#include "Cell.h"

namespace models {

class Region {
public:
	Region();
	Region(std::vector<Cell *> cells);
	void addCells(std::vector<Cell *> cells);
	bool isCompleted();
protected:
	std::vector<Cell *> cells;
};

}

#endif
