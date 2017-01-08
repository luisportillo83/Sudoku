#include <cassert>
#include "SaveController.h"

namespace controllers {

void SaveController::accept(OperationControllerVisitor * operationControllerVisitor) {
	operationControllerVisitor->visit(this);
}

void SaveController::save(std::string savedGameName) {
	assert(models::Game::instance()->getState() == models::State::SAVE);
	// utils::IO::instance()->writeLine("Partida " + savedGameName + " guardada correctamente");
}

void SaveController::continuePlay() {
	models::Game::instance()->setState(models::State::PLAY);
}

void SaveController::exitPlay() {
	models::Game::instance()->setState(models::State::FINAL);
}

}
