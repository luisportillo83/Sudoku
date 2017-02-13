#ifndef MODELS_BOARDINITIALIZER_H_
#define MODELS_BOARDINITIALIZER_H_

#include "Board.h"

namespace models {

class BoardInitializer {
public:
	enum DifficultyLevel {
		EASY = 0,
		HARD
	};
	static void initialize(Board * board, DifficultyLevel difficultyLevel);
private:
	static unsigned int NUMBER_OF_CELLS_TO_REMOVE_FROM_BOARD;
	static unsigned int numberOfEmptyCellsInBoard(DifficultyLevel difficultyLevel);
	static void removeCellsInBoardForLevel(Board * board, DifficultyLevel difficultyLevel);
};

}

#endif
