#include "BoardView.h"

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

void BoardView::print() {
	if (!automaticUpdateOfCellsGoingOn) {
		automaticUpdateOfCellsGoingOn = true;
		LPARAM cellValue = (LPARAM)models::Cell::CELL_NO_VALUE_CHARACTER;
			for (unsigned int i = 0; i < models::Board::NUMBER_OF_ROWS; i++) {
				for (unsigned int j = 0; j < models::Board::NUMBER_OF_COLUMNS; j++) {
					cellValue = (LPARAM)models::Cell::CELL_NO_VALUE_CHARACTER;
					if (models::Game::instance()->getValue(i, j) != models::Cell::CELL_NO_VALUE) {
						cellValue = (LPARAM)std::to_string(models::Game::instance()->getValue(i, j)).c_str();
					}
					SendMessage(handleBoard[(i * models::Board::NUMBER_OF_ROWS) + j],WM_SETTEXT,0, cellValue);
				}
			}
		automaticUpdateOfCellsGoingOn = false;
	}
}

void BoardView::updateBoard() {
	if (!automaticUpdateOfCellsGoingOn) {
		automaticUpdateOfCellsGoingOn = true;
		char cellCharacters[2];
		unsigned int cellValue = models::Cell::CELL_NO_VALUE;
		for (unsigned int i = 0; i < models::Board::NUMBER_OF_ROWS; i++) {
			for (unsigned int j = 0; j < models::Board::NUMBER_OF_COLUMNS; j++) {
				GetWindowText(handleBoard[(models::Board::NUMBER_OF_ROWS * i) + j], cellCharacters, 2);
				cellValue = models::Cell::CELL_NO_VALUE;
				if (strcmp(cellCharacters, models::Cell::CELL_NO_VALUE_CHARACTER)) {
					cellValue = atoi(cellCharacters);
				}
				// TODO, hacer un game-->canPutValue()
				// Y si no se puede poner, poner el valor anterior
				models::Game::instance()->setValue(i, j, cellValue);
			}
		}
		automaticUpdateOfCellsGoingOn = false;
	}
}

}
