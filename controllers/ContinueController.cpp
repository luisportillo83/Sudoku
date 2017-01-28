#include <cassert>
#include "ContinueController.h"

namespace controllers {

void ContinueController::accept(OperationControllerVisitor * operationControllerVisitor) {
	operationControllerVisitor->visit(this);
}

void ContinueController::continuePlaying() {
	assert(models::Game::instance()->getState() == models::State::FINAL);
	models::Game::instance()->clearBoard();
	models::Game::instance()->setState(models::State::PLAY);
}

void ContinueController::exit() {
	assert(models::Game::instance()->getState() == models::State::FINAL);
	models::Game::instance()->setState(models::State::EXIT);
}

}
