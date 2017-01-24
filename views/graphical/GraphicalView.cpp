#include <iostream>
#include <cassert>
#include <windows.h>
#include "GraphicalView.h"

namespace views {

char GraphicalView::CLASS_NAME[] = "SudokuClassName";
LPCTSTR GraphicalView::WINDOW_NAME = "Sudoku";
unsigned int GraphicalView::WINDOW_WIDTH = 330;
unsigned int GraphicalView::WINDOW_EIGHT = 405;
const unsigned int GraphicalView::CELL_WIDTH = 25;
const unsigned int GraphicalView::CELL_EIGHT = 25;
const unsigned int GraphicalView::LEFT_MARGIN = 25;
const unsigned int GraphicalView::TOP_MARGIN = 25 ;
const unsigned int GraphicalView::BUTTON_EIGHT = 35;
const unsigned int GraphicalView::BUTTON_WIDTH = 65;
const unsigned int GraphicalView::BUTTON_VERTICAL = 310;
const unsigned int GraphicalView::BUTTON_SEPARATION = 2;

// TODO tiene que ser global???
//HWND handleBoard[models::Board::NUMBER_OF_CELLS];
HWND handleBoard[81];

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
	//HWND handleBoard[models::Board::NUMBER_OF_CELLS];
	HWND handleNewGame, handleLoadGame, handleAbandonGame, handleSaveGame;

	switch(Msg)	{
	case WM_CREATE:
		for (unsigned int i = 0; i < models::Board::NUMBER_OF_ROWS; i++) {
			for (unsigned int j = 0; j < models::Board::NUMBER_OF_COLUMNS; j++) {
				handleBoard[(models::Board::NUMBER_OF_ROWS * i) + j] = CreateWindowExW(WS_EX_CLIENTEDGE,L"EDIT",L"",
						WS_TABSTOP|WS_CHILD|WS_VISIBLE|SS_CENTER|ES_NUMBER, GraphicalView::LEFT_MARGIN + (30 * j), GraphicalView::TOP_MARGIN + (30 * i),
						GraphicalView::CELL_WIDTH, GraphicalView::CELL_EIGHT, hWnd, (HMENU)HANDLE_BOARD, GetModuleHandle(NULL), NULL);
				SendMessage(handleBoard[(models::Board::NUMBER_OF_ROWS * i) + j], EM_LIMITTEXT, 1, 0);

				(new BoardView)->print();
			}
		}
		handleNewGame = CreateWindowExW(NULL,L"BUTTON",L"New", WS_TABSTOP|WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
			GraphicalView::LEFT_MARGIN, GraphicalView::BUTTON_VERTICAL, GraphicalView::BUTTON_WIDTH, GraphicalView::BUTTON_EIGHT,
			hWnd,(HMENU)HANDLE_NEW_GAME,GetModuleHandle(NULL),NULL);
		handleLoadGame = CreateWindowExW(NULL,L"BUTTON",L"Load", WS_TABSTOP|WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
			GraphicalView::LEFT_MARGIN + GraphicalView::BUTTON_WIDTH + GraphicalView::BUTTON_SEPARATION, GraphicalView::BUTTON_VERTICAL, GraphicalView::BUTTON_WIDTH, GraphicalView::BUTTON_EIGHT,
			hWnd,(HMENU)HANDLE_LOAD_GAME,GetModuleHandle(NULL),NULL);
		handleSaveGame = CreateWindowExW(NULL,L"BUTTON",L"Save", WS_TABSTOP|WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
			GraphicalView::LEFT_MARGIN + 2 * (GraphicalView::BUTTON_WIDTH + GraphicalView::BUTTON_SEPARATION), GraphicalView::BUTTON_VERTICAL, GraphicalView::BUTTON_WIDTH, GraphicalView::BUTTON_EIGHT,
			hWnd,(HMENU)HANDLE_SAVE_GAME,GetModuleHandle(NULL),NULL);
		handleAbandonGame = CreateWindowExW(NULL,L"BUTTON",L"Abandon", WS_TABSTOP|WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
			GraphicalView::LEFT_MARGIN + 3 * (GraphicalView::BUTTON_WIDTH + GraphicalView::BUTTON_SEPARATION), GraphicalView::BUTTON_VERTICAL, GraphicalView::BUTTON_WIDTH, GraphicalView::BUTTON_EIGHT,
			hWnd,(HMENU)HANDLE_ABANDON_GAME,GetModuleHandle(NULL),NULL);
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case HANDLE_BOARD:
			// TODO check game is finished?
			DefWindowProc(hWnd, Msg, wParam, lParam);
			break;
		case HANDLE_NEW_GAME:
			models::Game::instance()->setState(models::State::NEW);
			break;
		case HANDLE_LOAD_GAME:
			models::Game::instance()->setState(models::State::LOAD);
			break;
		case HANDLE_SAVE_GAME:
			models::Game::instance()->setState(models::State::SAVE);
			break;
		case HANDLE_ABANDON_GAME:
			models::Game::instance()->setState(models::State::ABANDON);
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

	gameView = new views::GameView();

	views::BoardView * boardView = new views::BoardView();
	newView = new views::NewView(winMainParameters, boardView);
	loadView = new views::LoadView(boardView);
	continueView = new views::ContinueView();
	saveView = new views::SaveView(boardView);
	abandonView = new views::AbandonView(boardView);
}

void GraphicalView::interact(controllers::OperationController * operationController) {
	assert(operationController != NULL);
	operationController->accept(this);
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
