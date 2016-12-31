#include "GameView.h"

namespace views {

GameView::GameView(BoardView * boardView) {
	this->boardView = boardView;
}

const int GameView::getUserAction() {
	/*
	utils::IO::instance()->writeLine("Acciones:");
	utils::IO::instance()->writeLine("1.- Mover de Descarte a Baraja");
	utils::IO::instance()->writeLine("2.- Mover de Baraja a Descarte");
	utils::IO::instance()->writeLine("3.- Mover de Descarte a Palo");
	utils::IO::instance()->writeLine("4.- Mover de Descarte a Trabajo");
	utils::IO::instance()->writeLine("5.- Mover de Trabajo a Palo");
	utils::IO::instance()->writeLine("6.- Mover de Trabajo a Trabajo");
	utils::IO::instance()->writeLine("7.- Mover de Palo a Trabajo");
	utils::IO::instance()->writeLine("8.- Deshacer movimiento");
	utils::IO::instance()->writeLine("9.- Rehacer movimiento");
	utils::IO::instance()->writeLine("10.- Salvar partida");
	utils::IO::instance()->writeLine("11.- Abandonar partida");
	return (utils::LimitedIntOption::instance()->read("Seleccione accion: ", 1, 11));
	*/
	return 0;
}

void GameView::interact(controllers::MoveController * moveController) {
	std::vector<char> pullOneCardOptions = {'y', 'n'};
	switch (getUserAction()) {
		case GameView::UNDO:
			break;
		case GameView::REDO:
			break;
		case GameView::SAVE:
			moveController->setState(models::State::SAVE);
			break;
		case GameView::ABANDON:
			moveController->setState(models::State::ABANDON);
			break;
	}
	//if (currentCommand) {
	if (true) {
		boardView->print(moveController);
	}
	if (moveController->isGameFinished()) {
		//utils::IO::instance()->writeLine("Felicidades! Has ganado!");
		moveController->setState(models::State::FINAL);
	}
}

}
