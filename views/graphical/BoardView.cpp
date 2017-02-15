#include "BoardView.h"

#include <iostream>

namespace views {

BoardView * BoardView::boardView;

const unsigned int BoardView::LEFT_MARGIN = 25;
const unsigned int BoardView::TOP_MARGIN = 25 ;
const unsigned int BoardView::CELL_WIDTH = 25;
const unsigned int BoardView::CELL_EIGHT = 25;
const unsigned int BoardView::CELL_SEPARATION = 5;

BoardView::BoardView() {
	handleBoard = new HWND[models::Board::NUMBER_OF_CELLS];
	automaticUpdateOfCellsGoingOn = false;
}

BoardView * BoardView::instance() {
	if (BoardView::boardView == NULL) {
		BoardView::boardView = new BoardView();
	}
	return BoardView::boardView;
}

void BoardView::create(HWND hWnd) {
	for (unsigned int i = 0; i < models::Board::NUMBER_OF_ROWS; i++) {
		for (unsigned int j = 0; j < models::Board::NUMBER_OF_COLUMNS; j++) {
			handleBoard[(models::Board::NUMBER_OF_ROWS * i) + j] = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"",
					WS_TABSTOP|WS_CHILD|WS_VISIBLE|SS_CENTER|ES_NUMBER,
					BoardView::LEFT_MARGIN + ((BoardView::CELL_WIDTH + BoardView::CELL_SEPARATION) * j),
					BoardView::TOP_MARGIN + ((BoardView::CELL_EIGHT + BoardView::CELL_SEPARATION) * i),
					BoardView::CELL_WIDTH, BoardView::CELL_EIGHT, hWnd, (HMENU)BoardView::HANDLE_BOARD, GetModuleHandle(NULL), NULL);
			SendMessage(handleBoard[(models::Board::NUMBER_OF_ROWS * i) + j], EM_LIMITTEXT, 1, 0);
		}
	}
}

void BoardView::printBoard() {
	if (!automaticUpdateOfCellsGoingOn) {
		automaticUpdateOfCellsGoingOn = true;
		for (unsigned int i = 0; i < models::Board::NUMBER_OF_ROWS; i++) {
			for (unsigned int j = 0; j < models::Board::NUMBER_OF_COLUMNS; j++) {
				printCell(i, j);
			}
		}
		automaticUpdateOfCellsGoingOn = false;
	}
}

void BoardView::printCell(unsigned int row, unsigned int column) {
	LPARAM cellValue = (LPARAM)models::Cell::CELL_NO_VALUE_CHARACTER;
	if (models::Game::instance()->getValue(row, column) != models::Cell::CELL_NO_VALUE) {
		cellValue = (LPARAM)std::to_string(models::Game::instance()->getValue(row, column)).c_str();
	}
	SendMessage(handleBoard[(row * models::Board::NUMBER_OF_ROWS) + column], WM_SETTEXT, 0, cellValue);
}

void BoardView::updateBoard() {
	if (!automaticUpdateOfCellsGoingOn) {
		automaticUpdateOfCellsGoingOn = true;
		unsigned int cellValue = models::Cell::CELL_NO_VALUE;
		for (unsigned int i = 0; i < models::Board::NUMBER_OF_ROWS; i++) {
			for (unsigned int j = 0; j < models::Board::NUMBER_OF_COLUMNS; j++) {
				cellValue = getCellBoardValue(i, j);
				if (models::Game::instance()->canPutValue(cellValue, i, j)) {
					models::Game::instance()->setValue(i, j, cellValue);
				}
				else {
					printCell(i, j);
				}
			}
		}
		automaticUpdateOfCellsGoingOn = false;
	}
}

unsigned int BoardView::getCellBoardValue(unsigned int row, unsigned int column) {
	unsigned int cellValue = models::Cell::CELL_NO_VALUE;
	char cellCharacters[2];
	GetWindowText(handleBoard[(models::Board::NUMBER_OF_ROWS * row) + column], cellCharacters, 2);
	cellValue = models::Cell::CELL_NO_VALUE;
	if (strcmp(cellCharacters, models::Cell::CELL_NO_VALUE_CHARACTER)) {
		cellValue = atoi(cellCharacters);
	}
	return cellValue;
}

}
