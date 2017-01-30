#ifndef VIEWS_CONTINUEVIEW_H_
#define VIEWS_CONTINUEVIEW_H_

#include "../../controllers/ContinueController.h"
#include "BoardView.h"

namespace views {

class ContinueView {
public:
	ContinueView(BoardView * boardView);
	void interact(controllers::ContinueController * continueController);
private:
	BoardView * boardView;
	static LPCTSTR WINDOW_NAME;
};

}

#endif
