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
	void print();
	void updateBoard();
private:
	BoardView();
	static BoardView * boardView;
	HWND *handleBoard;
	// TODO Poner un nombre  mejor o incluso hacer una clase en utils para takeMutex() y releaseMutex() ???
	bool automaticUpdateOfCells;
};

}

#endif
