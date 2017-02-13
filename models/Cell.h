#ifndef CELL_H_
#define CELL_H_

namespace models {

class Cell {
public:
	Cell();
	void setValue(unsigned int value);
	unsigned int getValue();
	bool isChangeable();
	// TODO improve these two methods
	void makeChangeable();
	void makeUnchangeable();

	static const unsigned int CELL_MAX_VALUE;
	static const unsigned int CELL_NO_VALUE;
	static const char * CELL_NO_VALUE_CHARACTER;

protected:
	unsigned int value;
	bool changeable;
};

}

#endif
