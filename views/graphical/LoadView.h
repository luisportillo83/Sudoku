#ifndef VIEWS_LOADVIEW_H_
#define VIEWS_LOADVIEW_H_

#include <string>
#include "../../utils/Message.h"
#include "../../controllers/LoadController.h"
#include "BoardView.h"

namespace views {

class LoadView {
public:
	LoadView();
	void interact(controllers::LoadController * loadController);
private:
	static std::string WINDOW_NAME;
};

}

#endif
