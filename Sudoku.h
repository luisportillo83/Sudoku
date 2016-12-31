#ifndef SUDOKU_H_
#define SUDOKU_H_

#include "Logic.h"
#include "View.h"

class Sudoku {
public:
	Sudoku(View * view, Logic * logic);
	void play();
protected:
	Logic * logic;
	View * view;
};

#endif
