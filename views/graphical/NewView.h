#ifndef VIEWS_CONSOLE_NEWVIEW_H_
#define VIEWS_CONSOLE_NEWVIEW_H_

#include "../../controllers/NewController.h"
#include "../../utils/WinMainParameters.h"
#include "BoardView.h"

namespace views {

class NewView {
public:
	NewView(utils::WinMainParameters * winMainParameters, BoardView * boardView);
	void interact(controllers::NewController * newController);
private:
	utils::WinMainParameters * winMainParameters;
	BoardView * boardView;
};

}

#endif
