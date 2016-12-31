#ifndef CONTROLLERS_GAMECONTROLLER_H_
#define CONTROLLERS_GAMECONTROLLER_H_

#include "../models/Game.h"
#include "../models/State.h"

namespace controllers {

class GameController {
protected:
	models::Game * game;
public:
	GameController(models::Game * game);
	models::State::StateValues getState();
	void setState(models::State::StateValues newState);
	bool isGameFinished();
};

}

#endif