#include <cassert>
#include "LoadController.h"

namespace controllers {

void LoadController::accept(OperationControllerVisitor * operationControllerVisitor) {
	operationControllerVisitor->visit(this);
}

void LoadController::load(std::string fileName) {
	assert(models::Game::instance()->getState() == models::State::LOAD);
	utils::SudokuFile::load(fileName);
	models::Game::instance()->setState(models::State::PLAY);
}

void LoadController::continuePlaying() {
	assert(models::Game::instance()->getState() == models::State::LOAD);
	models::Game::instance()->setState(models::State::PLAY);
}

}
