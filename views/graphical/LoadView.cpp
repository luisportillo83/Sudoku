#include <windows.h>
#include "LoadView.h"

namespace views {

LoadView::LoadView(BoardView * boardView) {
	this->boardView = boardView;
}

void LoadView::interact(controllers::LoadController * loadController) {
	if (models::Game::instance()->isGameOnGoing()) {
		if (IDNO == MessageBox(HWND(), "¿Quieres cargar una partida antigua y abandonar la actual?", "Load Game", MB_YESNO)) {
			loadController->continuePlaying();
		}
		else {
			loadController->load();
		}
	}
	else {
		loadController->load();
	}
	boardView->print();
}

}
