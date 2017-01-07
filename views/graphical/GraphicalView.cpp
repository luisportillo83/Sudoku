#include <cassert>
#include <windows.h>
#include "GraphicalView.h"

namespace views {

char GraphicalView::CLASS_NAME[] = "SudokuClassName";
LPCTSTR GraphicalView::WINDOW_NAME = "Sudoku";
unsigned int GraphicalView::WINDOW_WIDTH = 330;
unsigned int GraphicalView::WINDOW_EIGHT = 400;

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
	HWND hEditControls[81], handleNewGame, handleLoadGame, handleAbandonGame;
	switch(Msg)	{
	case WM_CREATE:
		for(int i=0; i<9; i++)
		{
			for(int j=0; j<9; j++)
			{
				hEditControls[9*i+j] = CreateWindowExW(WS_EX_CLIENTEDGE,L"EDIT",L"",
						WS_TABSTOP|WS_CHILD|WS_VISIBLE|SS_CENTER|ES_NUMBER, 24+(30*j), 24+(30*i), 24, 24,
						hWnd, (HMENU)HANDLE_BOARD, GetModuleHandle(NULL), NULL);
				SendMessage(hEditControls[9*i+j],EM_LIMITTEXT,1,0);
			}

		}
		handleNewGame=CreateWindowExW(NULL,L"BUTTON",L"New",
			WS_TABSTOP|WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
			30,310,75,35,hWnd,(HMENU)HANDLE_NEW_GAME,GetModuleHandle(NULL),NULL);
		handleLoadGame=CreateWindowExW(NULL,L"BUTTON",L"Load",
			WS_TABSTOP|WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
			120,310,75,35,hWnd,(HMENU)HANDLE_NEW_GAME,GetModuleHandle(NULL),NULL);
		handleLoadGame=CreateWindowExW(NULL,L"BUTTON",L"Abandon",
			WS_TABSTOP|WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
			210,310,75,35,hWnd,(HMENU)HANDLE_NEW_GAME,GetModuleHandle(NULL),NULL);
		break;
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case HANDLE_BOARD:
			// TODO numeros ...
			break;
		case HANDLE_NEW_GAME:
			// TODO numeros ...
			break;
		}
		break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		exit(0);
	case WM_DESTROY:
		PostQuitMessage(WM_QUIT);
		break;
	default:
		return DefWindowProc(hWnd, Msg, wParam, lParam);
	}
	return 0;
}

GraphicalView::GraphicalView(utils::WinMainParameters * winMainParameters) {
	winApp = new utils::WinApp(winMainParameters->getCurrentInstance(), GraphicalView::CLASS_NAME, MainWndProc);
	winApp->registerApp();

	utils::MainWnd window;
	window.Create(winMainParameters->getCurrentInstance(), GraphicalView::CLASS_NAME, GraphicalView::WINDOW_NAME, NULL,
			WS_OVERLAPPEDWINDOW, 0L, CW_USEDEFAULT, CW_USEDEFAULT, GraphicalView::WINDOW_WIDTH, GraphicalView::WINDOW_EIGHT);
	window.Show();

	views::BoardView * boardView = new views::BoardView(); // TODO es necesario?
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
