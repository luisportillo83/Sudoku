#include <windows.h>
#include "../../utils/WinApp.h"
#include "../../utils/MainWnd.h"
#include <cassert>
#include "StartView.h"

namespace views {

StartView::StartView() {
}

void StartView::interact(controllers::StartController * startController) {
	MSG   Msg;
	while(GetMessage(&Msg, NULL, 0, 0)) {
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
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
