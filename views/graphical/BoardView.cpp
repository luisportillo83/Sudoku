#include <cassert>
#include <windows.h>
#include "BoardView.h"

namespace views {

// TODO Improve this
extern HWND handleBoard[81];

BoardView::BoardView() {
}

void BoardView::print() {
	LPARAM cellValue = (LPARAM)L"";
	for (unsigned int i = 0; i < models::Board::NUMBER_OF_ROWS; i++) {
		for (unsigned int j = 0; j < models::Board::NUMBER_OF_COLUMNS; j++) {
			cellValue = (LPARAM)L"";
			if (models::Game::instance()->getValue(i, j) != models::Cell::CELL_NO_VALUE) {
				cellValue = (LPARAM)std::to_string(models::Game::instance()->getValue(i, j)).c_str();
			}
			SendMessage(handleBoard[(i * models::Board::NUMBER_OF_ROWS) + j],WM_SETTEXT,0, cellValue);
		}
	}
}

}
