#ifndef CELL_H_
#define CELL_H_

namespace models {

class Cell {
public:
	void setValue(unsigned int value);
	unsigned int getValue();

	static const unsigned int CELL_MAX_VALUE;

protected:
	unsigned int value;
};

}

#endif
