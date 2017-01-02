#include <cassert>
#include <algorithm>
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
	std::vector<Cell *> sortedCells(cells);

	// TODO move to util class
	assert(cells.size() == Cell::CELL_MAX_VALUE);
	for (unsigned int i = 0; i < cells.size(); i++) {
		if (cells.at(i)->getValue() != Cell::CELL_NO_VALUE) {
			return false;
		}
	}
	std::sort(cells.begin(), cells.end());
	for (unsigned int i = 0; i < cells.size(); i++) {
		if (cells.at(i)->getValue() != i) {
			return false;
		}
	}
	return true;
}

}
