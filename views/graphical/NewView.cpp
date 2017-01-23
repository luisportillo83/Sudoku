#include <windows.h>
#include <CommCtrl.h>

#include "NewView.h"

namespace views {

// TODO Improve this
extern HWND handleBoard[81];

NewView::NewView(utils::WinMainParameters * winMainParameters) {
	this->winMainParameters = winMainParameters;
}

void NewView::interact(controllers::NewController * newController) {
	//MessageBox(HWND(), "NewView", "NewView", MB_OK);

	// TODO ComboBox, put this in utils??

	int xpos = 100;            // Horizontal position of the window.
	int ypos = 100;            // Vertical position of the window.
	int nwidth = 200;          // Width of the window
	int nheight = 200;         // Height of the window
	HWND hwndParent =  HWND(); // Handle to the parent window

	HWND hWndComboBox = CreateWindow(WC_COMBOBOX, TEXT(""),
			CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
			xpos, ypos, nwidth, nheight, hwndParent, NULL, winMainParameters->getCurrentInstance(), NULL);

	SendMessage(hWndComboBox,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) L"luis");
	SendMessage(hWndComboBox,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) L"portillo");
	SendMessage(hWndComboBox,(UINT) CB_ADDSTRING,(WPARAM) 0,(LPARAM) L"hernandez");

	SendMessage(hWndComboBox, CB_SETCURSEL, (WPARAM)2, (LPARAM)0);

	newController->start(models::BoardInitializer::EASY);

	unsigned int cellValue = models::Cell::CELL_NO_VALUE;
	for (unsigned int i = 0; i < models::Board::NUMBER_OF_ROWS; i++) {
		for (unsigned int j = 0; j < models::Board::NUMBER_OF_COLUMNS; j++) {
			cellValue = models::Game::instance()->getValue(i, j);
			// TODO Improve this, poner una sola llamada a SendMessage!
			if (cellValue != models::Cell::CELL_NO_VALUE) {
				SendMessage(handleBoard[(i * models::Board::NUMBER_OF_ROWS) + j],WM_SETTEXT,0, (LPARAM)std::to_string(cellValue).c_str());
			}
			else {
				SendMessage(handleBoard[(i * models::Board::NUMBER_OF_ROWS) + j],WM_SETTEXT,0, (LPARAM)L"-");
			}

		}
	}
}

}
