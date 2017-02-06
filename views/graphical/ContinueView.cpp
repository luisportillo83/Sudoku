#include "ContinueView.h"

namespace views {

std::string ContinueView::WINDOW_NAME = "Continue Game";

ContinueView::ContinueView() {
}

void ContinueView::interact(controllers::ContinueController * continueController) {
	if (utils::Message::YesNoOptions::YES == utils::Message::printYesNoMessage("¿Quieres continuar jugando?", ContinueView::WINDOW_NAME)) {
		continueController->continuePlaying();
		views::BoardView::instance()->print();
	}
	else {
		continueController->exit();
	}
}

}
