#include <windows.h>
#include "NewView.h"

namespace views {

NewView::NewView(utils::WinMainParameters * winMainParameters, BoardView * boardView) {
	this->winMainParameters = winMainParameters;
	this->boardView = boardView;
}

void NewView::interact(controllers::NewController * newController) {
	if (models::Game::instance()->isGameOnGoing()) {
		if (IDNO == MessageBox(HWND(), "¿Quieres empezar una partida nueva y abandonar la actual?", "New Game", MB_YESNO)) {
			newController->continueCurrentGame();
			return;
		}
	}

	models::BoardInitializer::DifficultyLevel difficultyLevel;
	if (IDYES == MessageBox(HWND(), "Eres principiante?", "New Game", MB_YESNO)) {
		difficultyLevel = models::BoardInitializer::EASY;
	}
	else{
		difficultyLevel = models::BoardInitializer::HARD;
	}

	newController->start(difficultyLevel);
	boardView->print();
}

}
