#include "AbandonView.h"

namespace views {

AbandonView::AbandonView(BoardView * boardView) {
	this->boardView = boardView;
}

void AbandonView::interact(controllers::AbandonController * abandonController) {
	if (models::Game::instance()->isGameOnGoing()) {
		// TODO Preguntar si quieres guardar partida en curso o no o cancelar el abandonar
	}

	/* TODO
	std::vector<char> opcionesGuardarPartidaEnCurso = {'y', 'n'};
	if ('y' == utils::SingleCharOption::instance()->read("Quieres guardar la partida en curso? (y/n) ", opcionesGuardarPartidaEnCurso)) {
		std::string savedGameName =	utils::IO::instance()->readString("Dame el nombre de la partida a guardar: ");
		abandonController->save(savedGameName);
	}	*/
	abandonController->abandon();
	boardView->print();
}

}
