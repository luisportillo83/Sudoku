#ifndef VIEWS_CONTINUEVIEW_H_
#define VIEWS_CONTINUEVIEW_H_

#include <string>
#include "../../utils/Message.h"
#include "../../controllers/ContinueController.h"
#include "BoardView.h"

namespace views {

class ContinueView {
public:
	ContinueView();
	void interact(controllers::ContinueController * continueController);
private:
	static std::string WINDOW_NAME;
};

}

#endif
