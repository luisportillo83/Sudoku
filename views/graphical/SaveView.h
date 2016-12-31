#ifndef VIEWS_CONSOLE_SAVEVIEW_H_
#define VIEWS_CONSOLE_SAVEVIEW_H_

#include "../../controllers/SaveController.h"
#include "BoardView.h"

namespace views {

class SaveView {
public:
	SaveView(BoardView * boardView);
	void interact(controllers::SaveController * saveController);
private:
	BoardView * boardView;
};

}

#endif
