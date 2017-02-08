#ifndef MODELS_NUMBERCHECKER_H_
#define MODELS_NUMBERCHECKER_H_

#include <vector>
#include "Cell.h"

namespace models {

class NumberChecker {
public:
	bool isRowCompleted(unsigned int row, std::vector<Cell *> cells);
	bool isColumnCompleted(unsigned int column, std::vector<Cell *> cells);
private:
	bool hasAllNumbers(std::vector<Cell *> cells);
};

}

#endif
