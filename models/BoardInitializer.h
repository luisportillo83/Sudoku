#ifndef MODELS_BOARDINITIALIZER_H_
#define MODELS_BOARDINITIALIZER_H_

#include "Board.h"

namespace models {

class BoardInitializer {
public:
	enum DifficultyLevel {
		EASY = 0,
		MEDIUM,
		HARD
	};
	static void initialize(Board * board, DifficultyLevel difficultyLevel);
};

}

#endif
