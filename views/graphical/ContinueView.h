#ifndef VIEWS_CONTINUEVIEW_H_
#define VIEWS_CONTINUEVIEW_H_

#include "../../controllers/ContinueController.h"

namespace views {

class ContinueView {
public:
	ContinueView();
	void interact(controllers::ContinueController * continueController);
};

}

#endif
