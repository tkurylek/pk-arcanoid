/*
 * Position.h
 *
 *  Created on: 06-04-2014
 *      Author: tomek
 */

#ifndef POSITION_H_
#define POSITION_H_

class Position {
public:
	double x;
	double y;
	Position(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

#endif /* POSITION_H_ */