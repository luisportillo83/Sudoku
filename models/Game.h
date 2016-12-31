#ifndef MODELS_GAME_H_
#define MODELS_GAME_H_

#include "Board.h"
#include "State.h"

namespace models {

class Game {
public:
	Game();
	void createNewGame();
	bool isGameFinished();
	State::StateValues getState();
	void setState(State::StateValues newState);
	Board * getBoard();

	static const unsigned int MAX_NUMBER_OF_PLAYERS;
private:
	Board * board;
	State state;
};

}

#endif
