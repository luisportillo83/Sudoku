#include <windows.h>
#include "LoadView.h"

namespace views {

LPCTSTR LoadView::WINDOW_NAME = "Load Game";

LoadView::LoadView() {
}

void LoadView::interact(controllers::LoadController * loadController) {
	if (models::Game::instance()->isGameOnGoing()) {
		if (IDNO == MessageBox(HWND(), "¿Quieres cargar una partida antigua y abandonar la actual?", LoadView::WINDOW_NAME, MB_YESNO)) {
			loadController->continuePlaying();
			return;
		}
	}
	loadController->load();
	views::BoardView::instance()->print();
}

}
