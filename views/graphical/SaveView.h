#ifndef VIEWS_CONSOLE_SAVEVIEW_H_
#define VIEWS_CONSOLE_SAVEVIEW_H_

#include "../../controllers/SaveController.h"
#include "BoardView.h"
#include "../../utils/Message.h"
#include <string>
#include <ctime>

namespace views {

class SaveView {
public:
	SaveView();
	void interact(controllers::SaveController * saveController);
private:
	static std::string WINDOW_NAME;
	static unsigned int MAX_MESSAGEBOX_TEXT_SIZE;
	std::string getFileName();
};

}

#endif
