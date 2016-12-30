#include <cassert>
#include "Region.h"

namespace models {

Region::Region() {

}

Region::Region(std::vector<Cell *> cells) {
	assert(cells.size() == Cell::CELL_MAX_VALUE);
	this->cells = cells;
}

void Region::addCells(std::vector<Cell *> cells) {
	// TODO, is this really needed?
	assert(cells.size() == Cell::CELL_MAX_VALUE);
	this->cells = cells;
}

bool Region::isCompleted() {
	if (cells.size() != Cell::CELL_MAX_VALUE) {
		return false;
	}
	return true;
}

}
