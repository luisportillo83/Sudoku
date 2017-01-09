#include <windows.h>
#include "../../utils/WinApp.h"
#include "../../utils/MainWnd.h"
#include "GameView.h"

namespace views {

GameView::GameView(BoardView * boardView) {
	this->boardView = boardView;
}

void GameView::interact(controllers::MoveController * moveController) {
	MSG   Msg;
	while(GetMessage(&Msg, NULL, 0, 0) && models::Game::instance()->getState() == models::State::PLAY) {
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	/*
	std::vector<char> pullOneCardOptions = {'y', 'n'};
	switch (getUserAction()) {
		case GameView::UNDO:
			break;
		case GameView::REDO:
			break;
		case GameView::SAVE:
			moveController->setState(models::State::SAVE);
			break;
		case GameView::ABANDON:
			moveController->setState(models::State::ABANDON);
			break;
	}
	//if (currentCommand) {
	if (true) {
		boardView->print(moveController);
	}
	if (moveController->isGameFinished()) {
		//utils::IO::instance()->writeLine("Felicidades! Has ganado!");
		moveController->setState(models::State::FINAL);
	}*/
}

}
