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
	models::Game::instance()->setState(models::State::FINAL);
}

}
