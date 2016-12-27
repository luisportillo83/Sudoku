#include "Region.h"

namespace models {

const unsigned int Region::NUMBER_OF_CELLS = 9;

Region::Region() {
	cells = new Cell[Region::NUMBER_OF_CELLS];
}

}
