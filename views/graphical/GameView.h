#ifndef VIEWS_CONSOLE_GAMEVIEW_H_
#define VIEWS_CONSOLE_GAMEVIEW_H_

#include "../../controllers/MoveController.h"
#include "BoardView.h"

namespace views {

class GameView {
public:
	GameView(BoardView * boardView);
	void interact(controllers::MoveController * moveController);
private:
	BoardView * boardView;

	enum menuOptions {
		UNDO = 1,
		REDO = 2,
		SAVE = 3,
		ABANDON = 4
	};

	const int getUserAction();
};

}

#endif
