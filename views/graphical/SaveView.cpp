#include <algorithm>
#include <windows.h>
#include "SaveView.h"

namespace views {

LPCTSTR SaveView::WINDOW_NAME = "Save Game";

SaveView::SaveView(BoardView * boardView) {
	this->boardView = boardView;
}

void SaveView::interact(controllers::SaveController * saveController) {
	if (models::Game::instance()->isGameOnGoing()) {
		time_t timeNow = time(0);
		std::string fileName = ctime(&timeNow);
		fileName.erase(std::remove_if(fileName.begin(), fileName.end(), isspace),fileName.end());
		fileName.erase(std::remove_if(fileName.begin(), fileName.end(), ispunct),fileName.end());
		fileName.append(".sudoku");
		saveController->save(fileName);
		// TODO Hay alguna manera de poner el nombre del fichero en el MessageBox?
		MessageBox(HWND(), "Game saved!", SaveView::WINDOW_NAME, MB_OK);
	}
	saveController->continueCurrentGame();
}

}
