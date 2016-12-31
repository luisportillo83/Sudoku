#ifndef CONTROLLERS_STARTCONTROLLER_H_
#define CONTROLLERS_STARTCONTROLLER_H_

#include "OperationController.h"
#include "OperationControllerVisitor.h"

namespace controllers {

class StartController: public OperationController {
public:
	StartController(models::Game * game);
	void accept(OperationControllerVisitor * operationControllerVisitor);
	void newGame();
	void loadGame();
};

}

#endif
