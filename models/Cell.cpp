#include <cassert>
#include "Cell.h"

namespace models {

const unsigned int Cell::CELL_MAX_VALUE = 9;
const unsigned int Cell::CELL_NO_VALUE = 0;

Cell::Cell() {
	value = Cell::CELL_NO_VALUE;
}

void Cell::setValue(unsigned int value) {
	assert(value <= Cell::CELL_MAX_VALUE);
	this->value = value;
}

unsigned int Cell::getValue() {
	return this->value;
}

}
