#ifndef CONTROLLERS_LOADCONTROLLER_H_
#define CONTROLLERS_LOADCONTROLLER_H_

#include "OperationController.h"
#include "OperationControllerVisitor.h"

namespace controllers {

class LoadController: public OperationController {
public:
	void accept(OperationControllerVisitor * operationControllerVisitor);
	void load();
	void continuePlaying();
};

}

#endif
