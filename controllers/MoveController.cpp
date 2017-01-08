#include "MoveController.h"

namespace controllers {

void MoveController::accept(OperationControllerVisitor * operationControllerVisitor) {
	operationControllerVisitor->visit(this);
}

}
