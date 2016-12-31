#ifndef CONTROLLERS_MOVECONTROLLER_H_
#define CONTROLLERS_MOVECONTROLLER_H_

#include "OperationController.h"
#include "OperationControllerVisitor.h"

namespace controllers {

class MoveController: public OperationController {
public:
	MoveController(models::Game * game);
	void accept(OperationControllerVisitor * operationControllerVisitor);
};

}

#endif
