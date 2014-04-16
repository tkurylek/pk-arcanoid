/*
 * Paddle.h
 *
 *  Created on: 06-04-2014
 *      Author: tomek
 */

#ifndef PADDLE_H_
#define PADDLE_H_

#include "Drawable.h"
#include "Moveable.h"
#include "Position.h"
#include "Collisional.h"
#include <allegro.h>

class Paddle: public Drawable, public Moveable, public Collisional {
	const int PADDLE_WIDTH;
	const int PADDLE_HEIGHT;
	const int SPEED_X;
	Position position;
	Position previousPosition;
	HitPoints hitpoints;
	int direction;
public:
	Paddle() :
			PADDLE_WIDTH(100), PADDLE_HEIGHT(10), SPEED_X(1), position(
					Position(800 / 2 - PADDLE_WIDTH / 2, 600 - 80 - PADDLE_HEIGHT)), previousPosition(position), hitpoints(
					HitPoints(position.x, position.x + PADDLE_WIDTH, position.y, position.y + PADDLE_HEIGHT)), direction(
					1) {
	}

	void draw(BITMAP *buffer) {
		rectfill(buffer, position.x, position.y, position.x + PADDLE_WIDTH, position.y + PADDLE_HEIGHT,
				ColourMaker::RED);
	}

	void move() {
		previousPosition = position;
		direction = getDirectionFromKeyboard();
		position.x += direction;
		hitpoints = HitPoints(position.x, position.x + PADDLE_WIDTH, position.y, position.y + PADDLE_HEIGHT);
	}

	void collision() {
		position.x = previousPosition.x - direction;
		move();
	}

	HitPoints& getHitPoints() {
		return hitpoints;
	}

private:

	int getDirectionFromKeyboard() {
		if (key[KEY_LEFT]) {
			return -SPEED_X;
		} else if (key[KEY_RIGHT]) {
			return SPEED_X;
		}
		return 0;
	}
};

#endif /* PADDLE_H_ */
