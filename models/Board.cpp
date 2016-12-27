#include "Board.h"

namespace models {

const unsigned int Board::NUMBER_OF_REGIONS = 9;

Board::Board() {
	regions = new Region[Board::NUMBER_OF_REGIONS];
}

}
