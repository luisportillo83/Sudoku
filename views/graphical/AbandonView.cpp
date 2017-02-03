#include <windows.h>
#include "AbandonView.h"

namespace views {

LPCTSTR AbandonView::WINDOW_NAME = "Abandon Game";

AbandonView::AbandonView() {
}

void AbandonView::interact(controllers::AbandonController * abandonController) {
	if (models::Game::instance()->isGameOnGoing()) {
		if (IDYES == MessageBox(HWND(), "¿Quieres guardar la partida actual?", AbandonView::WINDOW_NAME, MB_YESNO)) {
			abandonController->save();
		}

		if (IDYES == MessageBox(HWND(), "¿Quieres abandonar la partida actual?", AbandonView::WINDOW_NAME, MB_YESNO)) {
			abandonController->abandon();
			views::BoardView::instance()->print();
		}
		else {
			abandonController->continueCurrentGame();
		}
	}
}

}
