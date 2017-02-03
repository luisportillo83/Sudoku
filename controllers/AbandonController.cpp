#include <cassert>
#include <iostream>
#include "AbandonController.h"

namespace controllers {

void AbandonController::accept(OperationControllerVisitor * operationControllerVisitor) {
	operationControllerVisitor->visit(this);
}

void AbandonController::save(std::string fileName) {
	assert(models::Game::instance()->getState() == models::State::ABANDON);
	utils::SudokuFile::save(fileName);
}

void AbandonController::abandon() {
	assert(models::Game::instance()->getState() == models::State::ABANDON);
	models::Game::instance()->setState(models::State::FINAL);
}

void AbandonController::continueCurrentGame() {
	assert(models::Game::instance()->getState() == models::State::ABANDON);
	models::Game::instance()->setState(models::State::PLAY);
}

}
