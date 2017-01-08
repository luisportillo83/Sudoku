#include "GameController.h"

namespace controllers {

GameController::GameController() {
}

models::State::StateValues GameController::getState() {
	return models::Game::instance()->getState();
}

void GameController::setState(models::State::StateValues newState) {
	models::Game::instance()->setState(newState);
}

bool GameController::isGameFinished() {
	return models::Game::instance()->isGameFinished();
}

}
