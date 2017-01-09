#ifndef MODELS_GAME_H_
#define MODELS_GAME_H_

#include "Board.h"
#include "State.h"

namespace models {

class Game {
public:
	static Game * instance();

	enum DifficultyLevel {
		EASY = 0,
		MEDIUM,
		HARD
	};

	void createNewGame(Game::DifficultyLevel difficultyLevel);
	bool isGameFinished();
	State::StateValues getState();
	void setState(State::StateValues newState);
	Board * getBoard();

private:
	Game();
	static Game * game;
	Board * board;
	State state;
};

}

#endif
