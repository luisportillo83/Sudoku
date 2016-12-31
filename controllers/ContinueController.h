#ifndef CONTROLLERS_CONTINUECONTROLLER_H_
#define CONTROLLERS_CONTINUECONTROLLER_H_

#include "OperationController.h"
#include "OperationControllerVisitor.h"

namespace controllers {

class ContinueController: public OperationController {
public:
	ContinueController(models::Game * game);
	void accept(OperationControllerVisitor * operationControllerVisitor);
	void continuePlaying();
	void exit();
};

}

#endif
