#include <cassert>
#include "ContinueController.h"

namespace controllers {

ContinueController::ContinueController(models::Game * game): OperationController(game) {
}

void ContinueController::accept(OperationControllerVisitor * operationControllerVisitor) {
	operationControllerVisitor->visit(this);
}

void ContinueController::continuePlaying() {
	assert(game->getState() == models::State::FINAL);
	game->setState(models::State::INITIAL);
}

void ContinueController::exit() {
	assert(game->getState() == models::State::FINAL);
	game->setState(models::State::EXIT);
}

}
