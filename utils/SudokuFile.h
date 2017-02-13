#ifndef UTILS_SUDOKUFILE_H_
#define UTILS_SUDOKUFILE_H_

#include <string.h>
#include <iostream>
#include <fstream>
#include "../models/Game.h"

namespace utils {

class SudokuFile {
public:
	static void save(std::string fileName);
	static void load(std::string fileName);
};

}

#endif
