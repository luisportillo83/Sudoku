#ifndef VIEWS_CONSOLE_ABANDONVIEW_H_
#define VIEWS_CONSOLE_ABANDONVIEW_H_

#include <string>
#include "../../utils/Message.h"
#include "../../controllers/AbandonController.h"
#include "BoardView.h"
#include <ctime>

namespace views {

class AbandonView {
public:
	AbandonView();
	void interact(controllers::AbandonController * abandonController);
private:
	static std::string WINDOW_NAME;
	static unsigned int MAX_MESSAGEBOX_TEXT_SIZE;
	std::string getFileName();
};

}

#endif
