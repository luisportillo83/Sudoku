#ifndef VIEWS_CONSOLE_ABANDONVIEW_H_
#define VIEWS_CONSOLE_ABANDONVIEW_H_

#include "../../controllers/AbandonController.h"
#include "BoardView.h"

namespace views {

class AbandonView {
public:
	AbandonView(BoardView * boardView);
	void interact(controllers::AbandonController * abandonController);
private:
	BoardView * boardView;
};

}

#endif
