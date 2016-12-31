#include <cassert>
#include "AbandonController.h"

namespace controllers {

AbandonController::AbandonController(models::Game * game): OperationController(game) {
}

void AbandonController::accept(OperationControllerVisitor * operationControllerVisitor) {
	operationControllerVisitor->visit(this);
}

void AbandonController::save(std::string savedGameName) {
	assert(game->getState() == models::State::ABANDON);
	//utils::IO::instance()->writeLine("Partida " + savedGameName + " guardada correctamente");
}

void AbandonController::abandon() {
	assert(game->getState() == models::State::ABANDON);
	game->setState(models::State::FINAL);
}

}
