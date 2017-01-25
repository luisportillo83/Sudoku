#include <ctime>
#include <math.h>
#include <algorithm>
#include <iostream>
#include "BoardInitializer.h"

namespace models {

// TODO Put default values back on
unsigned int BoardInitializer::INITIAL_NUMBER_OF_CELLS_TO_REMOVE = 2; //30;
unsigned int BoardInitializer::NUMBER_OF_CELLS_TO_REMOVE_WITH_EVERY_LEVEL = 0;//10;

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

	removeCellsInBoardForLevel(board, difficultyLevel);
}

unsigned int BoardInitializer::numberOfEmptyCellsInBoard(DifficultyLevel difficultyLevel) {
	return (BoardInitializer::INITIAL_NUMBER_OF_CELLS_TO_REMOVE - (difficultyLevel * BoardInitializer::NUMBER_OF_CELLS_TO_REMOVE_WITH_EVERY_LEVEL));
}

void BoardInitializer::removeCellsInBoardForLevel(Board * board, DifficultyLevel difficultyLevel) {
	unsigned int row = 0;
	unsigned int column = 0;
	for (unsigned int i = 0; i < numberOfEmptyCellsInBoard(difficultyLevel); i++) {
		do {
			row = rand()%(models::Board::NUMBER_OF_ROWS);
			column = rand()%(models::Board::NUMBER_OF_COLUMNS);
		} while (board->getValue(row, column) == models::Cell::CELL_NO_VALUE);
		board->clearCell(row, column);
	}
}

}
