#include "GameController.h"

namespace controllers {

GameController::GameController(models::Game * game) {
	if (game != NULL) {
		this->game = game;
	}
}

models::State::StateValues GameController::getState() {
	return game->getState();
}

void GameController::setState(models::State::StateValues newState) {
	game->setState(newState);
}

bool GameController::isGameFinished() {
	return game->isGameFinished();
}

}
