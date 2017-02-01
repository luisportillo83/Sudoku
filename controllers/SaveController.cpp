#include <cassert>
#include "SaveController.h"

namespace controllers {

void SaveController::accept(OperationControllerVisitor * operationControllerVisitor) {
	operationControllerVisitor->visit(this);
}

void SaveController::save() {
	assert(models::Game::instance()->getState() == models::State::SAVE);
	// TODO Save en un fichero cuyo nombre es la fecha, hora, minuto y segundos?
	std::string fileName = "luis";
	utils::SudokuFile::save(fileName);
}

void SaveController::continueCurrentGame() {
	assert(models::Game::instance()->getState() == models::State::SAVE);
	models::Game::instance()->setState(models::State::PLAY);
}

}
