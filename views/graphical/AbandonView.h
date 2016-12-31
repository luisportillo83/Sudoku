#ifndef VIEWS_CONSOLE_ABANDONVIEW_H_
#define VIEWS_CONSOLE_ABANDONVIEW_H_

#include "../../controllers/AbandonController.h"

namespace views {

class AbandonView {
public:
	AbandonView();
	void interact(controllers::AbandonController * abandonController);
};

}

#endif
