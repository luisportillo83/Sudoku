#ifndef CONTROLLERS_OPERATIONCONTROLLERVISITOR_H_
#define CONTROLLERS_OPERATIONCONTROLLERVISITOR_H_

namespace controllers {

class StartController;
class MoveController;
class NewController;
class LoadController;
class ContinueController;
class SaveController;
class AbandonController;

class OperationControllerVisitor {
public:
	virtual ~OperationControllerVisitor() {};
	virtual void visit(StartController * startController) = 0;
	virtual void visit(MoveController * moveController) = 0;
	virtual void visit(NewController * newController) = 0;
	virtual void visit(LoadController * loadController) = 0;
	virtual void visit(ContinueController * continueController) = 0;
	virtual void visit(SaveController * saveController) = 0;
	virtual void visit(AbandonController * abandonController) = 0;
};

}

#endif
