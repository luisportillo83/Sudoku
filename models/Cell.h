#ifndef CELL_H_
#define CELL_H_

namespace models {

class Cell {
public:
	Cell();
	void setValue(unsigned int value);
	unsigned int getValue();

	static const unsigned int CELL_MAX_VALUE;
	static const unsigned int CELL_NO_VALUE;

protected:
	unsigned int value;
};

}

#endif
