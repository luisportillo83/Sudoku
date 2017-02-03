#include <windows.h>
#include "ContinueView.h"

namespace views {

LPCTSTR ContinueView::WINDOW_NAME = "Continue Game";

ContinueView::ContinueView() {
}

void ContinueView::interact(controllers::ContinueController * continueController) {
	if (IDYES == MessageBox(HWND(), "¿Quieres continuar jugando?", ContinueView::WINDOW_NAME, MB_YESNO)) {
		continueController->continuePlaying();
		views::BoardView::instance()->print();
	}
	else {
		continueController->exit();
	}
}

}
