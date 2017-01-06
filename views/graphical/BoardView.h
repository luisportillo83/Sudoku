#ifndef VIEWS_CONSOLE_BOARDVIEW_H_
#define VIEWS_CONSOLE_BOARDVIEW_H_

#include "../../controllers/GameController.h"
#include "../../models/Board.h"

namespace views {

class BoardView {
public:
	BoardView();
	void print(controllers::GameController * gameController);

private:
	models::Board * board;
};

}

#endif
