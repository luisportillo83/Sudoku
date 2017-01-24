#include <cassert>
#include "AbandonController.h"

namespace controllers {

void AbandonController::accept(OperationControllerVisitor * operationControllerVisitor) {
	operationControllerVisitor->visit(this);
}

void AbandonController::save(std::string savedGameName) {
	assert(models::Game::instance()->getState() == models::State::ABANDON);
	//utils::IO::instance()->writeLine("Partida " + savedGameName + " guardada correctamente");
}

void AbandonController::abandon() {
	assert(models::Game::instance()->getState() == models::State::ABANDON);
	models::Game::instance()->clearBoard();
	// TODO Put FINAL state to see if player wants to play new game or exit completely
	// models::Game::instance()->setState(models::State::FINAL);
	models::Game::instance()->setState(models::State::PLAY);
}

}
