#ifndef VIEWS_CONSOLE_BOARDVIEW_H_
#define VIEWS_CONSOLE_BOARDVIEW_H_

#include "../../models/Board.h"
#include "../../models/Game.h"

namespace views {

class BoardView {
public:
	BoardView();
	void print();
	void updateBoard();
};

}

#endif
