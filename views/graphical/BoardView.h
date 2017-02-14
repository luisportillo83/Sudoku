#ifndef VIEWS_CONSOLE_BOARDVIEW_H_
#define VIEWS_CONSOLE_BOARDVIEW_H_

#include <windows.h>
#include "../../models/Board.h"
#include "../../models/Game.h"

namespace views {

class BoardView {
public:
	static BoardView * instance();

	static const unsigned int LEFT_MARGIN;
	static const unsigned int TOP_MARGIN;
	static const unsigned int CELL_WIDTH;
	static const unsigned int CELL_EIGHT;
	static const unsigned int CELL_SEPARATION;
	static constexpr const unsigned int HANDLE_BOARD = 101;

	void create(HWND hWnd);
	void printBoard();
	void printCell(unsigned int row, unsigned int column);
	void updateBoard();
	unsigned int getCellBoardValue(unsigned int row, unsigned int column);
private:
	BoardView();
	static BoardView * boardView;
	HWND *handleBoard;
	bool automaticUpdateOfCellsGoingOn;
};

}

#endif
