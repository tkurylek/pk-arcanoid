/*
 * Walls.h
 *
 *  Created on: 08-04-2014
 *      Author: tomek
 */

#ifndef WALLS_H_
#define WALLS_H_

#include "HitBox.h"
#include "Collisional.h"
#include "Drawable.h"

class LeftWall: public Collisional {
	HitPoints hitpoints;
public:
	LeftWall() :
			hitpoints(0, 0, 0, 600) {
	}
	void collision() {
	}
	HitPoints& getHitPoints() {
		return hitpoints;
	}
};

class Wall {
public:
	const static LeftWall LEFT_WALL;
};

class RightWall: public Collisional {
	HitPoints hitpoints;
public:
	RightWall() :
			hitpoints(800, 800, 0, 600) {
	}
	void collision() {
	}
	HitPoints& getHitPoints() {
		return hitpoints;
	}
};

class TopWall: public Collisional {
	HitPoints hitpoints;
public:
	TopWall() :
			hitpoints(0, 800, 0, 0) {
	}
	void collision() {
	}
	HitPoints& getHitPoints() {
		return hitpoints;
	}
};

class BottomWall: public Collisional {
	HitPoints hitpoints;
public:
	BottomWall() :
			hitpoints(0, 800, 600, 600) {
	}
	void collision() {
	}
	HitPoints& getHitPoints() {
		return hitpoints;
	}
};

#endif /* WALLS_H_ */
