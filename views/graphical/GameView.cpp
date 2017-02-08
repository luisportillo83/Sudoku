#include <cassert>
#include <windows.h>
#include "../../utils/WinApp.h"
#include "../../utils/MainWnd.h"
#include "GameView.h"

#include <iostream>

namespace views {

GameView::GameView() {
}

void GameView::interact(controllers::MoveController * moveController) {
	MSG   Msg;
	while(utils::MainWnd::getMessage(&Msg) &&
			(models::Game::instance()->getState() == models::State::INITIAL || models::Game::instance()->getState() == models::State::PLAY)) {
		utils::MainWnd::translateAndDispatchMessage(&Msg);
	}
}

}
