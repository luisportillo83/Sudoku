#include "ContinueView.h"

namespace views {

ContinueView::ContinueView() {
}

void ContinueView::interact(controllers::ContinueController * continueController) {

	std::vector<char> opcionesPartidaNuevaORecuperar = {'y', 'n'};

	/*
	if ('y' == utils::SingleCharOption::instance()->read("Quieres continuar jugando? (y/n) ", opcionesPartidaNuevaORecuperar)) {
		continueController->continuePlaying();
	}
	else {
		continueController->exit();
	}
	*/
}

}
