#ifndef VIEWS_CONSOLE_STARTVIEW_H_
#define VIEWS_CONSOLE_STARTVIEW_H_

#include "../../controllers/StartController.h"

namespace views {

class StartView {
public:
	StartView();
	void interact(controllers::StartController * startController);
};

}

#endif
