#ifndef COLLISIONAL_H_
#define COLLISIONAL_H_

#include "HitBox.h"

class Collisional {
public:
	/**
	 * Method called on collision with an object.
	 */
	virtual void collision() = 0;

	/**
	 * Coordinates of the object
	 */
	virtual HitPoints& getHitPoints() = 0;

	virtual ~Collisional() {
	}
};

#endif /* COLLISIONABLE_H_ */
