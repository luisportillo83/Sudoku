#include <cassert>
#include "BoardView.h"

namespace views {

BoardView::BoardView() {
	this->board = NULL;
}

void BoardView::initializeBoardView(models::Board * board) {
	this->board = board;
}

void BoardView::print(controllers::GameController * gameController) {
	/*
	if (!this->board) {
		initializeBoardView(gameController->getBoard());
	}
	*/

	// TODO print Board
}

}
