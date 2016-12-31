#ifndef VIEW_H_
#define VIEW_H_

#include "controllers/OperationController.h"
#include "controllers/OperationControllerVisitor.h"

class View: public controllers::OperationControllerVisitor {
public:
	virtual void interact(controllers::OperationController * operationController) = 0;
};

#endif
