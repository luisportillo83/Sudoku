#include "NewView.h"

namespace views {

std::string NewView::WINDOW_NAME = "New Game";

NewView::NewView() {
}

void NewView::interact(controllers::NewController * newController) {
	if (models::Game::instance()->isGameOnGoing()) {
		if (utils::Message::YesNoOptions::NO == utils::Message::printYesNoMessage("¿Quieres empezar una partida nueva y abandonar la actual?", NewView::WINDOW_NAME)) {
			newController->continueCurrentGame();
			return;
		}
	}

	models::BoardInitializer::DifficultyLevel difficultyLevel;

	if (utils::Message::YesNoOptions::YES == utils::Message::printYesNoMessage("Eres principiante?", NewView::WINDOW_NAME)) {
		difficultyLevel = models::BoardInitializer::EASY;
	}
	else{
		difficultyLevel = models::BoardInitializer::HARD;
	}

	newController->start(difficultyLevel);
	views::BoardView::instance()->printBoard();
}

}
