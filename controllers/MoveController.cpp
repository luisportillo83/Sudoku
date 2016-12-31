#include "MoveController.h"

namespace controllers {

MoveController::MoveController(models::Game * game): OperationController(game) {
}

void MoveController::accept(OperationControllerVisitor * operationControllerVisitor) {
	operationControllerVisitor->visit(this);
}

}
