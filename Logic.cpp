#include "Logic.h"

Logic::Logic() {
	game = new models::Game();
	startController = new controllers::StartController(game);
	moveController = new controllers::MoveController(game);
	newController = new controllers::NewController(game);
	loadController = new controllers::LoadController(game);
	continueController = new controllers::ContinueController(game);
	saveController = new controllers::SaveController(game);
	abandonController = new controllers::AbandonController(game);
}

controllers::OperationController * Logic::getOperationController() {
	switch (game->getState()) {
		case models::State::INITIAL:
			return startController;
		case models::State::LOAD:
			return loadController;
		case models::State::NEW:
			return newController;
		case models::State::PLAY:
			return moveController;
		case models::State::SAVE:
			return saveController;
		case models::State::ABANDON:
			return abandonController;
		case models::State::FINAL:
			return continueController;
		case models::State::EXIT:
		default:
			return NULL;
		}
}
