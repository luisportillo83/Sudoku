#include <cassert>
#include "SaveController.h"

namespace controllers {

SaveController::SaveController(models::Game * game): OperationController(game) {
}

void SaveController::accept(OperationControllerVisitor * operationControllerVisitor) {
	operationControllerVisitor->visit(this);
}

void SaveController::save(std::string savedGameName) {
	assert(game->getState() == models::State::SAVE);
	// utils::IO::instance()->writeLine("Partida " + savedGameName + " guardada correctamente");
}

void SaveController::continuePlay() {
	game->setState(models::State::PLAY);
}

void SaveController::exitPlay() {
	game->setState(models::State::FINAL);
}

}
