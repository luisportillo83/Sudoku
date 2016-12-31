#include "NewView.h"

namespace views {

NewView::NewView(BoardView * boardView) {
	this->boardView = boardView;
}

void NewView::interact(controllers::NewController * newController) {
	int users = 1;
	newController->start(users);
	boardView->print(newController);
}

}
