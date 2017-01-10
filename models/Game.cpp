#include "Game.h"

namespace models {

Game * Game::game;

Game::Game() {
	board = new Board();
	state.setState(State::PLAY);
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

Board * Game::getBoard() {
	return board;
}

}
