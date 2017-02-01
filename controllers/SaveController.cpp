#include <cassert>
#include "SaveController.h"

namespace controllers {

void SaveController::accept(OperationControllerVisitor * operationControllerVisitor) {
	operationControllerVisitor->visit(this);
}

void SaveController::save(std::string fileName) {
	assert(models::Game::instance()->getState() == models::State::SAVE);
	utils::SudokuFile::save(fileName);
}

void SaveController::continueCurrentGame() {
	assert(models::Game::instance()->getState() == models::State::SAVE);
	models::Game::instance()->setState(models::State::PLAY);
}

}
