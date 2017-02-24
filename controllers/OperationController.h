#ifndef CONTROLLERS_OPERATIONCONTROLLER_H_
#define CONTROLLERS_OPERATIONCONTROLLER_H_

#include "../models/Game.h"
#include "../models/State.h"

namespace controllers {

class OperationControllerVisitor;

class OperationController {
public:
	OperationController();
	virtual ~OperationController() {};
	virtual void accept(OperationControllerVisitor * operationControllerVisitor) = 0;
};

}

#endif
