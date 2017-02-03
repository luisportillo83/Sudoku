#ifndef VIEWS_CONSOLE_ABANDONVIEW_H_
#define VIEWS_CONSOLE_ABANDONVIEW_H_

#include "../../controllers/AbandonController.h"
#include "BoardView.h"
#include <ctime>

namespace views {

class AbandonView {
public:
	AbandonView();
	void interact(controllers::AbandonController * abandonController);
private:
	static LPCTSTR WINDOW_NAME;
	static unsigned int MAX_MESSAGEBOX_TEXT_SIZE;
	std::string getFileName();
};

}

#endif
