#include <cassert>
#include "StartView.h"

namespace views {

StartView::StartView(utils::WinMainParameters * winMainParameters) {
	this->winMainParameters = winMainParameters;
}

void StartView::interact(controllers::StartController * startController) {
	WNDPROC windowProc;
	assert(utils::WinMain::instance()->registerWindow(winMainParameters, windowProc));
	assert(utils::WinMain::instance()->createWindow());

	utils::WinMain::instance()->showWindow();
	utils::WinMain::instance()->updateWindow();
}

	/*
	std::vector<char> opcionesPartidaNuevaORecuperar = {'n', 'r'};

	if ('n' == utils::SingleCharOption::instance()->read("Partida nueva o recuperar partida? (n/r) ", opcionesPartidaNuevaORecuperar)) {
		startController->newGame();
	}
	else {
		startController->loadGame();
	}
	*/
}
