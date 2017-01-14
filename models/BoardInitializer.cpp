#include <ctime>
#include <math.h>
#include <algorithm>
#include <iostream>
#include "BoardInitializer.h"

namespace models {

unsigned int BoardInitializer::timesToGetRightRandomNumber = 1000;

void BoardInitializer::initialize(Board * board, DifficultyLevel difficultyLevel) {
	std::vector<unsigned int> table;
	int squareRoot = sqrt(board->NUMBER_OF_ROWS);

	for (unsigned int i = 0; i < board->NUMBER_OF_ROWS; i++) {
		for (unsigned int j = 0; j < board->NUMBER_OF_COLUMNS; j++) {
			table.push_back(((i * squareRoot) + (i / squareRoot) + j) % (squareRoot * squareRoot) + 1);
		}
	}

	// TODO random doesn't work as it doesn't follow Sudoku rules
	//std::random_shuffle(table.begin(), table.end());

	for (unsigned int i = 0; i < board->NUMBER_OF_ROWS; i++) {
		for (unsigned int j = 0; j < board->NUMBER_OF_COLUMNS; j++) {
			board->setValue(i, j, table.at(i * board->NUMBER_OF_ROWS + j));
			std::cout << table.at(i * board->NUMBER_OF_ROWS + j) << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

}
