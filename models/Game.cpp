#include <iostream>
#include "Game.h"

namespace models {

Game * Game::game;

Game::Game() {
	board = new Board();
	state.setState(State::INITIAL);
}

Game * Game::instance() {
	if (Game::game == NULL) {
		Game::game = new Game();
	}
	return Game::game;
}

void Game::createNewGame(BoardInitializer::DifficultyLevel difficultyLevel) {
	BoardInitializer::initialize(board, difficultyLevel);
	state.setState(State::PLAY);
}

bool Game::isGameOnGoing() {
	for (unsigned int i = 0; i < models::Board::NUMBER_OF_ROWS; i++) {
		for (unsigned int j = 0; j < models::Board::NUMBER_OF_COLUMNS; j++) {
			if (board->getValue(i, j) == models::Cell::CELL_NO_VALUE) {
				// TODO ...
			}
		}
	}
	return true;
}

bool Game::isGameFinished() {
	if (board->isCompleted()) {
		state.setState(State::FINAL);
		return true;
	}
	return false;
}

State::StateValues Game::getState() {
	return state.getState();
}

void Game::setState(State::StateValues newState) {
	state.setState(newState);
}

unsigned int Game::getValue(unsigned int row, unsigned int column) {
	return board->getValue(row, column);
}

void Game::setValue(unsigned int row, unsigned int column, unsigned int value) {
	board->setValue(row, column, value);
}

void Game::clearBoard() {
	board->clearBoard();
}

}
