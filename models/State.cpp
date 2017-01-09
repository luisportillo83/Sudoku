#include "State.h"

namespace models {

State::State() {
	state = PLAY;
}

void State::setState(StateValues newState) {
	this->state = newState;
}

State::StateValues State::getState() {
	return state;
}

}
