#ifndef COLOURMAKER_H_
#define COLOURMAKER_H_

#include "allegro.h"

class ColourMaker {
public:
	const static int WHITE;
	const static int RED;
	const static int GREEN;
	const static int BLUE;
	const static int BLACK;

	static int make(int red, int green, int blue) {
		return makecol(red, green, blue);
	}
};

const int ColourMaker::WHITE = 15;
const int ColourMaker::RED = 40;
const int ColourMaker::GREEN = 48;
const int ColourMaker::BLUE= 32;
const int ColourMaker::BLACK = 16;

#endif /* COLOURMAKER_H_ */
