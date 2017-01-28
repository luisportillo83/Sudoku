#include <windows.h>
#include "SaveView.h"

namespace views {

SaveView::SaveView(BoardView * boardView) {
	this->boardView = boardView;
}

void SaveView::interact(controllers::SaveController * saveController) {
	if (models::Game::instance()->isGameOnGoing()) {
		saveController->save();
		MessageBox(HWND(), "Game saved", "Save Game", MB_OK);
	}
	saveController->continueCurrentGame();
}

}
