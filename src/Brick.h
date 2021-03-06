#ifndef BRICK_H_
#define BRICK_H_

#include "Collisional.h"
#include "Drawable.h"
#include "HitBox.h"

using namespace std;

class Brick: public Collisional, public Drawable {
	const int BRICK_WIDTH;
	const int BRICK_HEIGHT;
	Position position;
	HitPoints hitbox;
	int hardness;

public:
	Brick(int x, int y, int hardness) :
	BRICK_WIDTH(100),
	BRICK_HEIGHT(20),
	position(Position(x, y)),
	hitbox(
			HitPoints(position.x,
					position.x + BRICK_WIDTH,
					position.y,
					position.y + BRICK_HEIGHT)) {
		if(hardness < 3) {
			this->hardness = hardness;
		} else {
			this->hardness = 3;
		}
	}

	void draw(BITMAP *buffer) {
		if (hardness > 0) {
			rectfill(buffer, position.x, position.y, position.x + BRICK_WIDTH, position.y + BRICK_HEIGHT,
					getColourByHardness());
		}
	}

	int getColourByHardness() {
		switch (hardness) {
		case 1:
			return ColourMaker::RED;
		case 2:
			return ColourMaker::YELLOW;
		default:
			return ColourMaker::GREEN;
		}
	}

	int getHardness() {
		return hardness;
	}

	void collision() {
		if (--hardness <= 0) {
			hide();
		}
	}

	HitPoints & getHitPoints() {
		return hitbox;
	}
private:
	void hide() {
		hardness = 0;
		hitbox = HitPoints();
	}
}
;

#endif /* BRICK_H_ */
