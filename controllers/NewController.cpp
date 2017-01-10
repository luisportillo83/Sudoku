#include <cassert>
#include "NewController.h"

namespace controllers {

void NewController::accept(OperationControllerVisitor * operationControllerVisitor) {
	operationControllerVisitor->visit(this);
}

void NewController::start(models::BoardInitializer::DifficultyLevel difficultyLevel) {
	assert(models::Game::instance()->getState() == models::State::NEW);
	// TODO, el parametro que sea el nivel de dificultad? Comprobarlo con el assert
	models::Game::instance()->createNewGame(models::BoardInitializer::EASY);
}

}
