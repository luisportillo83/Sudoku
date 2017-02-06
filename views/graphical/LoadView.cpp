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
	loadController->load();
	views::BoardView::instance()->print();
}

}
