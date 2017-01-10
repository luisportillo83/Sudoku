#include <ctime>
#include <iostream>
#include "BoardInitializer.h"

namespace models {

unsigned int BoardInitializer::timesToGetRightRandomNumber = 1000;

void BoardInitializer::initialize(Board * board, DifficultyLevel difficultyLevel) {
	int n = 3;
	for (unsigned int i = 0; i < board->NUMBER_OF_ROWS; i++) {
		for (unsigned int j = 0; j < board->NUMBER_OF_COLUMNS; j++) {
			board->setValue(i, j, (i*n + i/n + j) % (n*n) + 1);
			std::cout << board->getValue(i, j) << " ";
		}
		std::cout << std::endl;
	}
}

}
