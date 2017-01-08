#ifndef CONTROLLERS_COMMANDS_ABANDONCONTROLLER_H_
#define CONTROLLERS_COMMANDS_ABANDONCONTROLLER_H_

#include "OperationController.h"
#include "OperationControllerVisitor.h"

namespace controllers {

class AbandonController: public OperationController {
public:
	void accept(OperationControllerVisitor * operationControllerVisitor);
	void save(std::string savedGameName);
	void abandon();
};

}

#endif
