#include <cassert>
#include "StartController.h"

namespace controllers {

void StartController::accept(OperationControllerVisitor * operationControllerVisitor) {
	operationControllerVisitor->visit(this);
}

void StartController::newGame() {
	assert(models::Game::instance()->getState() == models::State::INITIAL);
	models::Game::instance()->setState(models::State::NEW);
}

void StartController::loadGame() {
	assert(models::Game::instance()->getState() == models::State::INITIAL);
	models::Game::instance()->setState(models::State::LOAD);
}

}
