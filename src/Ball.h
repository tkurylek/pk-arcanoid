#ifndef BALL_H_
#define BALL_H_

#include "Drawable.h"
#include "Moveable.h"
#include "Collisional.h"
#include "HitBox.h"
#include <math.h>

class Ball: public Drawable, public Moveable, public Collisional {
	Position position;
	Position previousPosition;
	const int RADIUS;
	const double SPIN_FORCE;
	HitPoints hitbox;
	enum Movement {
		VERTICAL, HORIZONTAL
	} movement;
	Position direction;
	int color;

public:

	Ball(int x = 395, int y = 30) :
			position(Position(x, y)),
					previousPosition(Position(x, y)),
					RADIUS(10),
					SPIN_FORCE(1.4),
					hitbox(
							HitPoints(position.x - RADIUS,
									position.x + RADIUS,
									position.y - RADIUS,
									position.y + RADIUS)),
					direction(Position(1, 1)) {
		movement = VERTICAL;
		color = ColourMaker::WHITE;
	}

	void move(int x, int y) {
		position.x = x;
		position.y = y;
		move();
	}

	void speedDown(double speed) {
		speedUp(-speed);
	}

	void draw(BITMAP *buffer) {
		circlefill(buffer, position.x, position.y, RADIUS, color);
	}

	void collision() {
		changeDirection();
		speedUp(.025);
		restoreLastPosition();
		move();
	}

	HitPoints& getHitPoints() {
		return hitbox;
	}

	void move() {
		rememberPosition();
		direction.x = boundSpeedToMax(direction.x, 4);
		direction.y = boundSpeedToMax(direction.y, 6);
		moveBallToDesignatedPosition();
	}

private:

	void speedUp(double speed) {
		if (direction.y > 0) {
			direction.y += speed;
		} else {
			direction.y -= speed;
		}
	}

	void changeDirection() {
		if (movement == VERTICAL) {
			direction.x *= -1;
		} else {
			direction.y *= -1;
			handlePaddleSpin();
		}
	}

	void handlePaddleSpin() {
		if (isInLineWithPaddle()) {
			if (key[KEY_LEFT]) {
				direction.x -= SPIN_FORCE;
			} else if (key[KEY_RIGHT]) {
				direction.x += SPIN_FORCE;
			}
		}
	}

	bool isInLineWithPaddle() {
		return position.y >= 480 && position.y <= 520;
	}

	void rememberPosition() {
		previousPosition = position;
	}

	void restoreLastPosition() {
		position = previousPosition;
	}

	double boundSpeedToMax(double speed, double maxSpeed) {
		return (speed > maxSpeed) ? maxSpeed : speed;
	}

	void moveBallToDesignatedPosition() {
		if (movement == VERTICAL) {
			position.y += direction.y;
			movement = HORIZONTAL;
		} else {
			position.x += direction.x;
			movement = VERTICAL;
		}
		updateHitpoints();
	}

	inline void updateHitpoints() {
		hitbox = HitPoints(position.x - RADIUS, position.x + RADIUS, position.y - RADIUS, position.y + RADIUS);
	}
};

#endif /* BALL_H_ */
