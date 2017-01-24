#ifndef VIEWS_CONSOLE_GAMEVIEW_H_
#define VIEWS_CONSOLE_GAMEVIEW_H_

#include "../../utils/WinMainParameters.h"
#include "../../controllers/MoveController.h"
#include "BoardView.h"

namespace views {

class GameView {
public:
	GameView();
	void interact(controllers::MoveController * moveController);
};

}

#endif
