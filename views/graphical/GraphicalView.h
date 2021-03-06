#ifndef VIEWS_GRAPHICAL_GRAPHICALVIEW_H_
#define VIEWS_GRAPHICAL_GRAPHICALVIEW_H_

#include "BoardView.h"
#include "GameView.h"
#include "NewView.h"
#include "LoadView.h"
#include "ContinueView.h"
#include "SaveView.h"
#include "AbandonView.h"
#include "../../controllers/OperationController.h"
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
#include "../../models/Game.h"

namespace views {

class GraphicalView: public View {
public:
	GraphicalView();
	GraphicalView(utils::WinMainParameters * winMainParameters);
	void interact(controllers::OperationController * operationController);
	void visit(controllers::NewController * newController);
	void visit(controllers::MoveController* moveController);
	void visit(controllers::LoadController * loadController);
	void visit(controllers::ContinueController * continueController);
	void visit(controllers::SaveController * saveController);
	void visit(controllers::AbandonController * abandonController);

	static char CLASS_NAME[];
	static LPCTSTR WINDOW_NAME;
	static LPCTSTR WINNING_MESSAGE;
	static unsigned int WINDOW_WIDTH;
	static unsigned int WINDOW_EIGHT;
	static const unsigned int BUTTON_WIDTH;
	static const unsigned int BUTTON_EIGHT;
	static const unsigned int BUTTON_VERTICAL;
	static const unsigned int BUTTON_SEPARATION;

	static constexpr const unsigned int HANDLE_NEW_GAME = 110;
	static constexpr const unsigned int HANDLE_LOAD_GAME = 111;
	static constexpr const unsigned int HANDLE_SAVE_GAME = 112;
	static constexpr const unsigned int HANDLE_ABANDON_GAME = 113;

private:
	utils::WinApp * winApp;
	GameView * gameView;
	NewView * newView;
	LoadView * loadView;
	ContinueView * continueView;
	SaveView * saveView;
	AbandonView * abandonView;
};

}

#endif
