#include "LoadView.h"

namespace views {

LoadView::LoadView(BoardView * boardView) {
	this->boardView = boardView;
}

void LoadView::interact(controllers::LoadController * loadController) {
	if (models::Game::instance()->isGameOnGoing()) {
		// TODO Preguntar si quieres guardar partida en curso o no o cancelar el cargar
	}
	loadController->load();
}

}
