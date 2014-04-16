/*
 * Collisionable.h
 *
 *  Created on: 06-04-2014
 *      Author: tomek
 */

#ifndef COLLISIONAL_H_
#define COLLISIONAL_H_

#include "HitBox.h"

class Collisional {
public:
	virtual void collision() = 0;
	virtual HitPoints& getHitPoints() = 0;
	virtual ~Collisional() {
	}
};

#endif /* COLLISIONABLE_H_ */
