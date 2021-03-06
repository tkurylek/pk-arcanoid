#ifndef BONUS_H_
#define BONUS_H_

#include "Position.h"
#include "Drawable.h"
#include "Collisional.h"
#include "HitBox.h"
#include "RandomUtils.h"

/**
 * Klasa wspólna dla bonusów dostępnych w grze. Po
 * wystąpieniu kolizji z piłką bonus zostaje aktywowany.
 */
class Bonus: public Drawable, public Collisional {

	const int RADIUS;
	const int EXPIRATION_TIME;
	Position position;
	bool visible;
	HitPoints hitbox;
	double startTime;

public:

	Bonus(int x = RandomUtils::randomInt(50, 750), int y = RandomUtils::randomInt(250, 400)) :
			RADIUS(20),
					EXPIRATION_TIME(10),
					position(Position(x, y)),
					visible(false),
					hitbox(HitPoints()) {
		startTime = (unsigned int) -1;
	}

	/**
	 * Aktywuje bonus. Metoda wywoływana jest podczas kolizji z piłką.
	 */
	virtual void activate() = 0;

	virtual void draw(BITMAP *buffer) {
		if (visible) {
			circlefill(buffer, position.x, position.y, RADIUS, ColourMaker::YELLOW);
		}
		showRandomly();
		hideAfterExpirationTime();
	}

	virtual void collision() {
		if (visible) {
			hide();
			activate();
		}
	}

	virtual HitPoints& getHitPoints() {
		return hitbox;
	}

protected:

	bool getVisible() {
		return visible;
	}

private:

	/**
	 * Losowo pokazuje bonus na polu gry.
	 */
	void showRandomly() {
		if (!visible && RandomUtils::randomInt(0, 5000) == 50) {
			show();
		}
	}

	void show() {
		startTime = clock();
		visible = true;
		hitbox = HitPoints(position.x - RADIUS,
				position.x + RADIUS,
				position.y - RADIUS,
				position.y + RADIUS);
	}

	void hideAfterExpirationTime() {
		if (visible && getVisibleTime() > EXPIRATION_TIME) {
			hide();
		}
	}

	double inline getVisibleTime() {
		return (clock() - startTime) / CLOCKS_PER_SEC;
	}

	void hide() {
		visible = false;
		hitbox = HitPoints();
	}
};

#endif /* BONUS_H_ */
