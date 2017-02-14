#ifndef MODELS_GAME_H_
#define MODELS_GAME_H_

#include "Board.h"
#include "BoardInitializer.h"
#include "State.h"

namespace models {

class Game {
public:
	static Game * instance();

	void createNewGame(BoardInitializer::DifficultyLevel difficultyLevel);
	bool isGameFinished();
	bool isGameOnGoing();
	void setValue(unsigned int row, unsigned int column, unsigned int value);
	bool canPutValue(unsigned int value, unsigned int row, unsigned int column);
	State::StateValues getState();
	void setState(State::StateValues newState);
	unsigned int getValue(unsigned int row, unsigned int column);
	void clearBoard();

private:
	Game();
	static Game * game;
	Board * board;
	State state;
};

}

#endif
