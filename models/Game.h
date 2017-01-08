#ifndef MODELS_GAME_H_
#define MODELS_GAME_H_

#include "Board.h"
#include "State.h"

namespace models {

class Game {
public:
	static Game * instance();

	void createNewGame();
	bool isGameFinished();
	State::StateValues getState();
	void setState(State::StateValues newState);
	Board * getBoard();

	// TODO enum con los niveles de dificultad y que sea parametro de createNewGame

private:
	Game();
	static Game * game;
	Board * board;
	State state;
};

}

#endif
