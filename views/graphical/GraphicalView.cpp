#include <cassert>
#include <iostream>
#include <windows.h>
#include "GraphicalView.h"

namespace views {

char GraphicalView::CLASS_NAME[] = "SudokuClassName";
LPCTSTR GraphicalView::WINDOW_NAME = "Sudoku";
unsigned int GraphicalView::WINDOW_WIDTH = 330;
unsigned int GraphicalView::WINDOW_EIGHT = 405;
const unsigned int GraphicalView::BUTTON_EIGHT = 35;
const unsigned int GraphicalView::BUTTON_WIDTH = 65;
const unsigned int GraphicalView::BUTTON_VERTICAL = 310;
const unsigned int GraphicalView::BUTTON_SEPARATION = 2;

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
	//HWND handleBoard[models::Board::NUMBER_OF_CELLS];
	HWND handleNewGame, handleLoadGame, handleAbandonGame, handleSaveGame;

	switch(Msg)	{
	case WM_CREATE:
		views::BoardView::instance()->create(hWnd);
		views::BoardView::instance()->print();
		handleNewGame = CreateWindowExW(NULL,L"BUTTON",L"New", WS_TABSTOP|WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
			BoardView::LEFT_MARGIN, GraphicalView::BUTTON_VERTICAL, GraphicalView::BUTTON_WIDTH, GraphicalView::BUTTON_EIGHT,
			hWnd, (HMENU)GraphicalView::HANDLE_NEW_GAME, GetModuleHandle(NULL), NULL);
		handleLoadGame = CreateWindowExW(NULL,L"BUTTON",L"Load", WS_TABSTOP|WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
			BoardView::LEFT_MARGIN + GraphicalView::BUTTON_WIDTH + GraphicalView::BUTTON_SEPARATION, GraphicalView::BUTTON_VERTICAL, GraphicalView::BUTTON_WIDTH, GraphicalView::BUTTON_EIGHT,
			hWnd, (HMENU)GraphicalView::HANDLE_LOAD_GAME, GetModuleHandle(NULL), NULL);
		handleSaveGame = CreateWindowExW(NULL,L"BUTTON",L"Save", WS_TABSTOP|WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
			BoardView::LEFT_MARGIN + 2 * (GraphicalView::BUTTON_WIDTH + GraphicalView::BUTTON_SEPARATION), GraphicalView::BUTTON_VERTICAL, GraphicalView::BUTTON_WIDTH, GraphicalView::BUTTON_EIGHT,
			hWnd, (HMENU)GraphicalView::HANDLE_SAVE_GAME, GetModuleHandle(NULL), NULL);
		handleAbandonGame = CreateWindowExW(NULL,L"BUTTON",L"Abandon", WS_TABSTOP|WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,
			BoardView::LEFT_MARGIN + 3 * (GraphicalView::BUTTON_WIDTH + GraphicalView::BUTTON_SEPARATION), GraphicalView::BUTTON_VERTICAL, GraphicalView::BUTTON_WIDTH, GraphicalView::BUTTON_EIGHT,
			hWnd, (HMENU)GraphicalView::HANDLE_ABANDON_GAME, GetModuleHandle(NULL), NULL);
		break;

	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case BoardView::HANDLE_BOARD:
			// TODO this update causes problems!
			if (models::Game::instance()->getState() == models::State::PLAY) {
				//TODO (new BoardView)->updateBoard();
			}

			if ((models::Game::instance()->getState() == models::State::PLAY) and models::Game::instance()->isGameFinished()) {
				MessageBox(NULL, "CONGRATULATIONS! YOU WIN!", GraphicalView::WINDOW_NAME, NULL);
			}
			DefWindowProc(hWnd, Msg, wParam, lParam);

			break;
		case GraphicalView::HANDLE_NEW_GAME:
			models::Game::instance()->setState(models::State::NEW);
			break;
		case GraphicalView::HANDLE_LOAD_GAME:
			models::Game::instance()->setState(models::State::LOAD);
			break;
		case GraphicalView::HANDLE_SAVE_GAME:
			models::Game::instance()->setState(models::State::SAVE);
			break;
		case GraphicalView::HANDLE_ABANDON_GAME:
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
	newView = new views::NewView();
	loadView = new views::LoadView();
	continueView = new views::ContinueView();
	saveView = new views::SaveView();
	abandonView = new views::AbandonView();
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
