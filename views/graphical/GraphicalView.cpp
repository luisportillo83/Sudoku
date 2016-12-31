#include <cassert>
#include "GraphicalView.h"

namespace views {

GraphicalView::GraphicalView() {
	views::BoardView * boardView = new views::BoardView();
	gameView = new views::GameView(boardView);
	startView = new views::StartView();
	newView = new views::NewView(boardView);
	loadView = new views::LoadView(boardView);
	continueView = new views::ContinueView();
	saveView = new views::SaveView(boardView);
	abandonView = new views::AbandonView();
}

void GraphicalView::interact(controllers::OperationController * operationController) {
	assert(operationController != NULL);
	operationController->accept(this);
}

void GraphicalView::visit(controllers::StartController * startController) {
	startView->interact(startController);
}

void GraphicalView::visit(controllers::MoveController* moveController) {
	gameView->interact(moveController);
}

void GraphicalView::visit(controllers::NewController * newController) {
	newView->interact(newController);
}

void GraphicalView::visit(controllers::LoadController * loadController) {
	loadView->interact(loadController);
}

void GraphicalView::visit(controllers::ContinueController * continueController) {
	continueView->interact(continueController);
}

void GraphicalView::visit(controllers::SaveController * saveController) {
	saveView->interact(saveController);
}

void GraphicalView::visit(controllers::AbandonController * abandonController) {
	abandonView->interact(abandonController);
}

}