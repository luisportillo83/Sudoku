#include <algorithm>
#include <windows.h>
#include <stdio.h>
#include "AbandonView.h"

namespace views {

LPCTSTR AbandonView::WINDOW_NAME = "Abandon Game";
unsigned int AbandonView::MAX_MESSAGEBOX_TEXT_SIZE = 100;

AbandonView::AbandonView() {
}

void AbandonView::interact(controllers::AbandonController * abandonController) {
	if (models::Game::instance()->isGameOnGoing()) {
		if (IDYES == MessageBox(HWND(), "¿Quieres guardar la partida actual?", AbandonView::WINDOW_NAME, MB_YESNO)) {
			std::string fileName = getFileName();
			abandonController->save(fileName);
			char messageBoxText[AbandonView::MAX_MESSAGEBOX_TEXT_SIZE];
			sprintf(messageBoxText, "Game saved in file:\n%s", fileName.c_str());
			MessageBox(HWND(), messageBoxText, AbandonView::WINDOW_NAME, MB_OK);
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

std::string AbandonView::getFileName() {
	time_t timeNow = time(0);
	std::string fileName = ctime(&timeNow);
	fileName.erase(std::remove_if(fileName.begin(), fileName.end(), isspace),fileName.end());
	fileName.erase(std::remove_if(fileName.begin(), fileName.end(), ispunct),fileName.end());
	fileName.append(".sudoku");
	return fileName;
}

}
