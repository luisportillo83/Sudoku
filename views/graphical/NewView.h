#ifndef VIEWS_CONSOLE_NEWVIEW_H_
#define VIEWS_CONSOLE_NEWVIEW_H_

#include "../../controllers/NewController.h"

namespace views {

class NewView {
public:
	NewView();
	void interact(controllers::NewController * newController);
};

}

#endif
