#ifndef PADDLE_H_
#define PADDLE_H_

#include "Drawable.h"
#include "Moveable.h"
#include "Position.h"
#include "Collisional.h"
#include <allegro.h>

class Paddle: public Drawable, public Moveable, public Collisional {
	int paddleWidth;
	const int PADDLE_HEIGHT;
	const double SPEED_X;
	Position position;
	Position previousPosition;
	HitPoints hitpoints;
	double direction;
	public:
	Paddle() :
			paddleWidth(100), PADDLE_HEIGHT(10), SPEED_X(2.0), position(
					Position(800 / 2 - paddleWidth / 2, 600 - 80 - PADDLE_HEIGHT)), previousPosition(position), hitpoints(
					HitPoints(position.x, position.x + paddleWidth, position.y, position.y + PADDLE_HEIGHT)), direction(
					SPEED_X) {
	}

	void makeWider(int addition) {
		if (paddleWidth < 200) {
			paddleWidth += addition;
		}
	}

	void makeShorter(int subtraction) {
		if (paddleWidth > 50) {
			paddleWidth -= subtraction;
		}
	}

	void draw(BITMAP *buffer) {
		rectfill(buffer, position.x, position.y, position.x + paddleWidth, position.y + PADDLE_HEIGHT,
				ColourMaker::RED);
	}

	void move() {
		previousPosition = position;
		direction = getDirectionFromKeyboard();
		position.x += direction;
		hitpoints = HitPoints(position.x, position.x + paddleWidth, position.y, position.y + PADDLE_HEIGHT);
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
