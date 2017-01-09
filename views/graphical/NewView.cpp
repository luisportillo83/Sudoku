#include <windows.h>
#include "NewView.h"

namespace views {

NewView::NewView() {
}

void NewView::interact(controllers::NewController * newController) {
	MessageBox(HWND(), "Sudoku", "About", MB_OK);
	newController->start(0);
}

}
