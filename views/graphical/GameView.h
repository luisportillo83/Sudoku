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
		MOVE_WASTE_STACK = 1,
		MOVE_STACK_WASTE = 2,
		MOVE_WASTE_FOUNDATION = 3,
		MOVE_WASTE_TABLEAU = 4,
		MOVE_TABLEAU_FOUNDATION = 5,
		MOVE_TABLEAU_TABLEAU = 6,
		MOVE_FOUNDATION_TABLEAU = 7,
		UNDO = 8,
		REDO = 9,
		SAVE = 10,
		ABANDON = 11
	};

	const int getUserAction();
};

}

#endif
