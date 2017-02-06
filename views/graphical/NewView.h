#ifndef VIEWS_CONSOLE_NEWVIEW_H_
#define VIEWS_CONSOLE_NEWVIEW_H_

#include <string>
#include "../../utils/Message.h"
#include "../../controllers/NewController.h"
#include "BoardView.h"

namespace views {

class NewView {
public:
	NewView();
	void interact(controllers::NewController * newController);
private:
	static std::string WINDOW_NAME;
};

}

#endif
