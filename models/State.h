#ifndef MODELS_STATE_H_
#define MODELS_STATE_H_

#include <string>

namespace models {

class State {
public:
	enum StateValues
	{
		PLAY = 0,
		LOAD,
		NEW,
		ABANDON,
		SAVE,
		FINAL,
		EXIT
	};

	State();
	void setState(StateValues newState);
	State::StateValues getState();
private:
	StateValues state;
};

}

#endif
