#include <cassert>
#include <windows.h>
#include "NewController.h"

namespace controllers {

void NewController::accept(OperationControllerVisitor * operationControllerVisitor) {
	operationControllerVisitor->visit(this);
}

void NewController::start(models::BoardInitializer::DifficultyLevel difficultyLevel) {
	assert(models::Game::instance()->getState() == models::State::NEW);
	models::Game::instance()->createNewGame(models::BoardInitializer::EASY);
}

void NewController::continueCurrentGame() {
	assert(models::Game::instance()->getState() == models::State::NEW);
	models::Game::instance()->setState(models::State::PLAY);
}

}
