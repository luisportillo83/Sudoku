#include <algorithm>
#include <stdio.h>
#include "SaveView.h"

namespace views {

std::string SaveView::WINDOW_NAME = "Save Game";
unsigned int SaveView::MAX_MESSAGEBOX_TEXT_SIZE = 100;

SaveView::SaveView() {
}

void SaveView::interact(controllers::SaveController * saveController) {
	if (models::Game::instance()->isGameOnGoing()) {
		std::string fileName = getFileName();
		saveController->save(fileName);
		char messageBoxText[SaveView::MAX_MESSAGEBOX_TEXT_SIZE];
		sprintf(messageBoxText, "Game saved in file:\n%s", fileName.c_str());
		utils::Message::printOkMessage(messageBoxText, SaveView::WINDOW_NAME);
	}
	saveController->continueCurrentGame();
}

std::string SaveView::getFileName() {
	time_t timeNow = time(0);
	std::string fileName = ctime(&timeNow);
	fileName.erase(std::remove_if(fileName.begin(), fileName.end(), isspace),fileName.end());
	fileName.erase(std::remove_if(fileName.begin(), fileName.end(), ispunct),fileName.end());
	fileName.append(".sudoku");
	return fileName;
}

}
