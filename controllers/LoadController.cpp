#include <cassert>
#include "LoadController.h"

namespace controllers {

LoadController::LoadController(models::Game * game): OperationController(game) {
}

void LoadController::accept(OperationControllerVisitor * operationControllerVisitor) {
	operationControllerVisitor->visit(this);
}

void LoadController::load() {
	assert(game->getState() == models::State::LOAD);
	// Load game
	game->setState(models::State::PLAY);
}

}
