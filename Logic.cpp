#include "Logic.h"

Logic::Logic() {
	moveController = new controllers::MoveController();
	newController = new controllers::NewController();
	loadController = new controllers::LoadController();
	continueController = new controllers::ContinueController();
	saveController = new controllers::SaveController();
	abandonController = new controllers::AbandonController();
}

controllers::OperationController * Logic::getOperationController() {
	switch (models::Game::instance()->getState()) {
		case models::State::PLAY:
			return moveController;
		case models::State::LOAD:
			return loadController;
		case models::State::NEW:
			return newController;
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
