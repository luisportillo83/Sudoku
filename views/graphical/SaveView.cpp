#include <windows.h>
#include "SaveView.h"

namespace views {

LPCTSTR SaveView::WINDOW_NAME = "Save Game";

SaveView::SaveView(BoardView * boardView) {
	this->boardView = boardView;
}

void SaveView::interact(controllers::SaveController * saveController) {
	if (models::Game::instance()->isGameOnGoing()) {
		saveController->save();
		MessageBox(HWND(), "Game saved", SaveView::WINDOW_NAME, MB_OK);
	}
	saveController->continueCurrentGame();
}

}
