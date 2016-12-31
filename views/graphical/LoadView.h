#ifndef VIEWS_LOADVIEW_H_
#define VIEWS_LOADVIEW_H_

#include "../../controllers/LoadController.h"
#include "BoardView.h"

namespace views {

class LoadView {
public:
	LoadView(BoardView * boardView);
	void interact(controllers::LoadController * loadController);
private:
	BoardView * boardView;
};

}

#endif
