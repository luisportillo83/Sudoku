#ifndef CONTROLLERS_SAVECONTROLLER_H_
#define CONTROLLERS_SAVECONTROLLER_H_

#include "OperationController.h"
#include "OperationControllerVisitor.h"
#include "../utils/SudokuFile.h"

namespace controllers {

class SaveController: public OperationController {
public:
	void accept(OperationControllerVisitor * operationControllerVisitor);
	void save();
	void continueCurrentGame();
};

}

#endif
