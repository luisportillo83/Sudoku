#ifndef CONTROLLERS_NEWCONTROLLER_H_
#define CONTROLLERS_NEWCONTROLLER_H_

#include "OperationController.h"
#include "OperationControllerVisitor.h"

namespace controllers {

class NewController: public OperationController {
public:
	NewController(models::Game * game);
	void accept(OperationControllerVisitor * operationControllerVisitor);
	void start(int numUsers);
};

}

#endif
