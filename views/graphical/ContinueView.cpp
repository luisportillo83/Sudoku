#include <windows.h>
#include "ContinueView.h"

namespace views {

ContinueView::ContinueView(BoardView * boardView) {
	this->boardView = boardView;
}

void ContinueView::interact(controllers::ContinueController * continueController) {
	if (IDYES == MessageBox(HWND(), "¿Quieres continuar jugando?", "Continue Game", MB_YESNO)) {
		continueController->continuePlaying();
		boardView->print();
	}
	else {
		continueController->exit();
	}
}

}
