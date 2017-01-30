#include <windows.h>
#include "ContinueView.h"

namespace views {

LPCTSTR ContinueView::WINDOW_NAME = "Continue Game";

ContinueView::ContinueView(BoardView * boardView) {
	this->boardView = boardView;
}

void ContinueView::interact(controllers::ContinueController * continueController) {
	if (IDYES == MessageBox(HWND(), "¿Quieres continuar jugando?", ContinueView::WINDOW_NAME, MB_YESNO)) {
		continueController->continuePlaying();
		boardView->print();
	}
	else {
		continueController->exit();
	}
}

}
