#ifndef BONUS_H_
#define BONUS_H_

#include "Position.h"
#include "Drawable.h"
#include "Collisional.h"
#include "HitBox.h"
#include "RandomUtils.h"

class Bonus: public Drawable, public Collisional {

	Position position;
	bool hit;
	const int RADIUS;
	HitPoints hitbox;
	public:

	Bonus(int x = RandomUtils::randomInt(50, 750), int y = RandomUtils::randomInt(250, 400)) :
			position(Position(x, y)),
					hit(false),
					RADIUS(20),
					hitbox(HitPoints()) {
		markAsHit();
	}

	/**
	 * Activates the bonus. This method is triggered on collision.
	 */
	virtual void activate() = 0;

	virtual void draw(BITMAP *buffer) {
		if (!hit) {
			circlefill(buffer, position.x, position.y, RADIUS, ColourMaker::YELLOW);
		}
		if(RandomUtils::randomInt(0, 50000) == 50) {
			markAsUnhit();
		}
	}

	virtual void collision() {
		if (!hit) {
			markAsHit();
			activate();
		}
	}

	void markAsHit() {
		hit = true;
		hitbox = HitPoints();
	}

	void markAsUnhit() {
		hit = false;
		hitbox = HitPoints(position.x - RADIUS,
				position.x + RADIUS,
				position.y - RADIUS,
				position.y + RADIUS);
	}

	virtual HitPoints& getHitPoints() {
		return hitbox;
	}
};

#endif /* BONUS_H_ */
