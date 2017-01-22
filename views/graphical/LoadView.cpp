#include "LoadView.h"

namespace views {

LoadView::LoadView(BoardView * boardView) {
	this->boardView = boardView;
}

void LoadView::interact(controllers::LoadController * loadController) {
	loadController->load();
}

}
