/*
 * Ball.h
 *
 *  Created on: 06-04-2014
 *      Author: tomek
 */

#ifndef BALL_H_
#define BALL_H_

#include "Drawable.h"
#include "Moveable.h"
#include "Collisional.h"
#include "HitBox.h"

class Ball: public Drawable, public Moveable, public Collisional {
	Position position;
	Position previousPosition;
	const int RADIUS;
	HitPoints hitbox;
	enum Movement {
		VERTICAL, HORIZONTAL
	} movement;
	Position direction;
	int color;
public:

	Ball(int x = 395, int y = 30) :
			position(Position(x, y)), previousPosition(Position(x, y)), RADIUS(10), hitbox(
					HitPoints(position.x - RADIUS, position.x + RADIUS, position.y - RADIUS, position.y + RADIUS)), direction(
					Position(1, 1)) {
		movement = VERTICAL;
		color = ColourMaker::WHITE;
	}

	void draw(BITMAP *buffer) {
		circlefill(buffer, position.x, position.y, RADIUS, color);
	}

	void collision() {
		if (movement == VERTICAL) {
			direction.x *= -1;
		} else {
			direction.y *= -1;
		}
		if (color == ColourMaker::WHITE) {
			color = ColourMaker::GREEN;
		} else {
			color = ColourMaker::WHITE;
		}
		position = previousPosition;
		move();
	}

	HitPoints& getHitPoints() {
		return hitbox;
	}

	void move() {
		previousPosition = position;
		if (movement == VERTICAL) {
			position.y += direction.y;
			movement = HORIZONTAL;
		} else {
			position.x += direction.x;
			movement = VERTICAL;
		}
		hitbox = HitPoints(position.x - RADIUS, position.x + RADIUS, position.y - RADIUS, position.y + RADIUS);
	}
};

#endif /* BALL_H_ */
