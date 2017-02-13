#include "SudokuFile.h"

namespace utils {

void SudokuFile::save(std::string fileName) {
	std::ofstream sudokuFile;
	sudokuFile.open(fileName.c_str());

	for (unsigned int i = 0; i < models::Board::NUMBER_OF_ROWS; i++) {
		for (unsigned int j = 0; j < models::Board::NUMBER_OF_COLUMNS; j++) {
			sudokuFile << models::Game::instance()->getValue(i, j) << " ";
		}
		sudokuFile << std::endl;
	}

	sudokuFile.close();
}

void SudokuFile::load(std::string fileName) {
	models::Game::instance()->clearBoard();
}


}
