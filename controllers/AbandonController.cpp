#include <cassert>
#include <iostream>

#include "AbandonController.h"

namespace controllers {

void AbandonController::accept(OperationControllerVisitor * operationControllerVisitor) {
	operationControllerVisitor->visit(this);
}

void AbandonController::save() {
	assert(models::Game::instance()->getState() == models::State::ABANDON);
	// TODO save (igual que el de save controller?)
}

void AbandonController::abandon() {
	assert(models::Game::instance()->getState() == models::State::ABANDON);
	models::Game::instance()->clearBoard();
	// TODO Put FINAL state to see if player wants to play new game or exit completely
	// models::Game::instance()->setState(models::State::FINAL);
	models::Game::instance()->setState(models::State::PLAY);
}

void AbandonController::continueCurrentGame() {
	assert(models::Game::instance()->getState() == models::State::ABANDON);
	models::Game::instance()->setState(models::State::PLAY);
}

}
