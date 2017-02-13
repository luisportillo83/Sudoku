#include <ctime>
#include <math.h>
#include <algorithm>
#include <iostream>
#include "BoardInitializer.h"

namespace models {

unsigned int BoardInitializer::NUMBER_OF_CELLS_TO_REMOVE_FROM_BOARD = 25;

void BoardInitializer::initialize(Board * board, DifficultyLevel difficultyLevel) {
	std::vector<unsigned int> table;
	int squareRoot = sqrt(board->NUMBER_OF_ROWS);

	for (unsigned int i = 0; i < board->NUMBER_OF_ROWS; i++) {
		for (unsigned int j = 0; j < board->NUMBER_OF_COLUMNS; j++) {
			table.push_back(((i * squareRoot) + (i / squareRoot) + j) % (squareRoot * squareRoot) + 1);
		}
	}

	for (unsigned int i = 0; i < board->NUMBER_OF_ROWS; i++) {
		for (unsigned int j = 0; j < board->NUMBER_OF_COLUMNS; j++) {
			board->setValue(i, j, table.at(i * board->NUMBER_OF_ROWS + j));
		}
	}

	removeCellsInBoardForLevel(board, difficultyLevel);
}

unsigned int BoardInitializer::numberOfEmptyCellsInBoard(DifficultyLevel difficultyLevel) {
	unsigned int numberOfEmptyCellsInBoard = 0;
	if (difficultyLevel == BoardInitializer::EASY) {
		numberOfEmptyCellsInBoard = BoardInitializer::NUMBER_OF_CELLS_TO_REMOVE_FROM_BOARD;
	}
	else if (difficultyLevel == BoardInitializer::HARD) {
		numberOfEmptyCellsInBoard = 2 * BoardInitializer::NUMBER_OF_CELLS_TO_REMOVE_FROM_BOARD;
	}
	return numberOfEmptyCellsInBoard;
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
