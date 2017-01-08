#ifndef VIEWS_GRAPHICAL_GRAPHICALVIEW_H_
#define VIEWS_GRAPHICAL_GRAPHICALVIEW_H_

#include "BoardView.h"
#include "StartView.h"
#include "GameView.h"
#include "NewView.h"
#include "LoadView.h"
#include "ContinueView.h"
#include "SaveView.h"
#include "AbandonView.h"
#include "../../controllers/OperationController.h"
#include "../../controllers/StartController.h"
#include "../../controllers/NewController.h"
#include "../../controllers/MoveController.h"
#include "../../controllers/LoadController.h"
#include "../../controllers/ContinueController.h"
#include "../../controllers/SaveController.h"
#include "../../controllers/AbandonController.h"
#include "../../View.h"
#include "../../utils/WinMainParameters.h"
#include "../../utils/WinApp.h"
#include "../../utils/MainWnd.h"
#include "../../models/Board.h"

// TODO Poner esto como parte de la clase?
#define HANDLE_BOARD 101
#define HANDLE_NEW_GAME 110
#define HANDLE_LOAD_GAME 111
#define HANDLE_SAVE_GAME 112
#define HANDLE_ABANDON_GAME 113

namespace views {

class GraphicalView: public View {
public:
	GraphicalView();
	GraphicalView(utils::WinMainParameters * winMainParameters);
	void interact(controllers::OperationController * operationController);
	void visit(controllers::StartController * startController);
	void visit(controllers::NewController * newController);
	void visit(controllers::MoveController* moveController);
	void visit(controllers::LoadController * loadController);
	void visit(controllers::ContinueController * continueController);
	void visit(controllers::SaveController * saveController);
	void visit(controllers::AbandonController * abandonController);

	static char CLASS_NAME[];
	static LPCTSTR WINDOW_NAME;
	static unsigned int WINDOW_WIDTH;
	static unsigned int WINDOW_EIGHT;
	static const unsigned int CELL_WIDTH;
	static const unsigned int CELL_EIGHT;
	static const unsigned int LEFT_MARGIN;
	static const unsigned int TOP_MARGIN;

private:
	utils::WinApp * winApp;
	StartView * startView;
	GameView * gameView;
	NewView * newView;
	LoadView * loadView;
	ContinueView * continueView;
	SaveView * saveView;
	AbandonView * abandonView;
};

}

#endif
