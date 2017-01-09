#include <windows.h>
#include "NewView.h"

namespace views {

NewView::NewView(BoardView * boardView) {
	this->boardView = boardView;
}

void NewView::interact(controllers::NewController * newController) {
	MSG   Msg;
	while(GetMessage(&Msg, NULL, 0, 0) && models::Game::instance()->getState() == models::State::NEW) {
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	int users = 1;
	newController->start(users);
	boardView->print(newController);
}

}
