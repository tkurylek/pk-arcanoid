/*
 * Moveable.h
 *
 *  Created on: 06-04-2014
 *      Author: tomek
 */

#ifndef MOVEABLE_H_
#define MOVEABLE_H_

class Moveable {
public:
	virtual void move() = 0;
	virtual ~Moveable() {

	}
};

#endif /* MOVEABLE_H_ */
