#include <algorithm>
#include <stdio.h>
#include "AbandonView.h"

namespace views {

std::string AbandonView::WINDOW_NAME = "Abandon Game";
unsigned int AbandonView::MAX_MESSAGEBOX_TEXT_SIZE = 100;

AbandonView::AbandonView() {
}

void AbandonView::interact(controllers::AbandonController * abandonController) {
	if (models::Game::instance()->isGameOnGoing()) {
		if (utils::Message::YesNoOptions::YES == utils::Message::printYesNoMessage("¿Quieres guardar la partida actual?", AbandonView::WINDOW_NAME)) {
			std::string fileName = getFileName();
			abandonController->save(fileName);
			char messageBoxText[AbandonView::MAX_MESSAGEBOX_TEXT_SIZE];
			sprintf(messageBoxText, "Game saved in file:\n%s", fileName.c_str());
			utils::Message::printOkMessage(messageBoxText, AbandonView::WINDOW_NAME);
		}

		if (utils::Message::YesNoOptions::YES == utils::Message::printYesNoMessage("¿Quieres abandonar la partida actual?", AbandonView::WINDOW_NAME)) {
			abandonController->abandon();
			views::BoardView::instance()->printBoard();
		}
		else {
			abandonController->continueCurrentGame();
		}
	}
	else {
		abandonController->continueCurrentGame();
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
