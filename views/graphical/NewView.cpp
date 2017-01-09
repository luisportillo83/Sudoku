#include <windows.h>
#include "NewView.h"

namespace views {

NewView::NewView(BoardView * boardView) {
	this->boardView = boardView;
}

void NewView::interact(controllers::NewController * newController) {
	newController->start(0);
}

}
