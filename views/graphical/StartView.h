#ifndef VIEWS_CONSOLE_STARTVIEW_H_
#define VIEWS_CONSOLE_STARTVIEW_H_

#include "../../controllers/StartController.h"
#include "../../utils/WinMainParameters.h"
#include "../../utils/WinMain.h"

namespace views {

class StartView {
public:
	StartView(utils::WinMainParameters * winMainParameters);
	void interact(controllers::StartController * startController);
private:
	utils::WinMainParameters * winMainParameters;
};

}

#endif
