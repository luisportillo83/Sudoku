#include <cassert>
#include "NewController.h"

namespace controllers {

NewController::NewController(models::Game * game): OperationController(game) {
}

void NewController::accept(OperationControllerVisitor * operationControllerVisitor) {
	operationControllerVisitor->visit(this);
}

void NewController::start(int numUsers) {
	assert(game->getState() == models::State::NEW);
	// TODO, el parametro que sea el nivel de dificultad? Comprobarlo con el assert
	game->createNewGame();
}

}
