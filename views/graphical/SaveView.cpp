#include "SaveView.h"

namespace views {

SaveView::SaveView(BoardView * boardView) {
	this->boardView = boardView;
}

void SaveView::interact(controllers::SaveController * saveController) {
	/*
	std::string savedGameName =	utils::IO::instance()->readString("Dame el nombre de la partida a guardar: ");
	saveController->save(savedGameName);

	std::vector<char> opcionesSeguirJugandoONo = {'y', 'n'};
	if ('y' == utils::SingleCharOption::instance()->read("Quieres seguir la partida? (y/n) ", opcionesSeguirJugandoONo)) {
		saveController->continuePlay();
		boardView->print(saveController);
	}
	else {
		saveController->exitPlay();
	}
	*/
}

}
