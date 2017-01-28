#include <windows.h>
#include "AbandonView.h"

namespace views {

AbandonView::AbandonView(BoardView * boardView) {
	this->boardView = boardView;
}

void AbandonView::interact(controllers::AbandonController * abandonController) {
	if (models::Game::instance()->isGameOnGoing()) {
		if (IDYES == MessageBox(HWND(), "¿Quieres guardar la partida actual?", "Abondon Game", MB_YESNO)) {
			abandonController->save();
		}

		if (IDYES == MessageBox(HWND(), "¿Quieres abandonar la partida actual?", "Abondon Game", MB_YESNO)) {
			abandonController->abandon();
			boardView->print();
		}
		else {
			abandonController->continueCurrentGame();
		}
	}
}

}
