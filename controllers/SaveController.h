#ifndef CONTROLLERS_SAVECONTROLLER_H_
#define CONTROLLERS_SAVECONTROLLER_H_

#include "OperationController.h"
#include "OperationControllerVisitor.h"

namespace controllers {

class SaveController: public OperationController {
public:
	SaveController(models::Game * game);
	void accept(OperationControllerVisitor * operationControllerVisitor);
	void save(std::string savedGameName);
	void exitPlay();
	void continuePlay();
};

}

#endif
