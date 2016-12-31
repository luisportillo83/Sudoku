#include <cassert>
#include "StartController.h"

namespace controllers {

StartController::StartController(models::Game * game): OperationController(game) {
}

void StartController::accept(OperationControllerVisitor * operationControllerVisitor) {
	operationControllerVisitor->visit(this);
}

void StartController::newGame() {
	assert(game->getState() == models::State::INITIAL);
	game->setState(models::State::NEW);
}

void StartController::loadGame() {
	assert(game->getState() == models::State::INITIAL);
	game->setState(models::State::LOAD);
}

}
