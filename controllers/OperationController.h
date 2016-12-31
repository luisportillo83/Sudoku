#ifndef CONTROLLERS_OPERATIONCONTROLLER_H_
#define CONTROLLERS_OPERATIONCONTROLLER_H_

#include "GameController.h"

namespace controllers {

class OperationControllerVisitor;

class OperationController: public GameController {
public:
	OperationController(models::Game * game);
	virtual ~OperationController() {};
	virtual void accept(OperationControllerVisitor * operationControllerVisitor) = 0;
};

}

#endif
