#include <cassert>
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
}

}
