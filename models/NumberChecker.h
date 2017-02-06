#ifndef MODELS_NUMBERCHECKER_H_
#define MODELS_NUMBERCHECKER_H_

#include <vector>
#include "Cell.h"

namespace models {

class NumberChecker {
public:
	NumberChecker();
	bool isRowCompleted(unsigned int row);
	bool isColumnCompleted(unsigned int column);
	bool isRegionCompleted(unsigned int region);
private:
	bool hasAllNumbers(std::vector<Cell *> cells);
};

}

#endif
