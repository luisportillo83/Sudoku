#ifndef CONTROLLERS_LOADCONTROLLER_H_
#define CONTROLLERS_LOADCONTROLLER_H_

#include "OperationController.h"
#include "OperationControllerVisitor.h"
#include "../utils/SudokuFile.h"

namespace controllers {

class LoadController: public OperationController {
public:
	void accept(OperationControllerVisitor * operationControllerVisitor);
	void load(std::string fileName);
	void continuePlaying();
};

}

#endif
