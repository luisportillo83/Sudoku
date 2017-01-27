#include <windows.h>
#include "NewView.h"

namespace views {

NewView::NewView(utils::WinMainParameters * winMainParameters, BoardView * boardView) {
	this->winMainParameters = winMainParameters;
	this->boardView = boardView;
}

void NewView::interact(controllers::NewController * newController) {
	if (models::Game::instance()->isGameOnGoing()) {
		if (IDYES == MessageBox(HWND(), "¿Quieres empezar una partida nueva y abandonar la actual?", "New Game", MB_YESNO)) {
			// TODO
			MessageBox(HWND(), "YES!", "New Game", MB_OK);
		}
	}

	// TODO Seleccionar LEVEL en un ComboBox o similar?
	MessageBox(HWND(), "Selecciona el nivel de dificultad", "New Game", MB_OK);
	newController->start(models::BoardInitializer::EASY);
	boardView->print();
}

}
