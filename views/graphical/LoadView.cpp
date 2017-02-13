#include "LoadView.h"

namespace views {

std::string LoadView::WINDOW_NAME = "Load Game";

LoadView::LoadView() {
}

void LoadView::interact(controllers::LoadController * loadController) {
	if (models::Game::instance()->isGameOnGoing()) {
		if (utils::Message::YesNoOptions::NO == utils::Message::printYesNoMessage("¿Quieres cargar una partida antigua y abandonar la actual?", LoadView::WINDOW_NAME)) {
			loadController->continuePlaying();
			return;
		}
	}
	std::string fileName = getFileName();
	loadController->load(fileName);
	views::BoardView::instance()->print();
}

std::string LoadView::getFileName() {
	return "test.sudoku";
}

}
