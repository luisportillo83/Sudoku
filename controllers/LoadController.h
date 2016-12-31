#ifndef CONTROLLERS_LOADCONTROLLER_H_
#define CONTROLLERS_LOADCONTROLLER_H_

#include "OperationController.h"
#include "OperationControllerVisitor.h"

namespace controllers {

class LoadController: public OperationController {
public:
	LoadController(models::Game * game);
	void accept(OperationControllerVisitor * operationControllerVisitor);
	void load();
};

}

#endif
