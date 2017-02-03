#ifndef VIEWS_CONSOLE_NEWVIEW_H_
#define VIEWS_CONSOLE_NEWVIEW_H_

#include "../../controllers/NewController.h"
#include "BoardView.h"

namespace views {

class NewView {
public:
	NewView();
	void interact(controllers::NewController * newController);
private:
	static LPCTSTR WINDOW_NAME;
};

}

#endif
