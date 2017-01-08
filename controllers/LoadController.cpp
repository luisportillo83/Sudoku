#include <cassert>
#include "LoadController.h"

namespace controllers {

void LoadController::accept(OperationControllerVisitor * operationControllerVisitor) {
	operationControllerVisitor->visit(this);
}

void LoadController::load() {
	assert(models::Game::instance()->getState() == models::State::LOAD);
	// Load game
	models::Game::instance()->setState(models::State::PLAY);
}

}
