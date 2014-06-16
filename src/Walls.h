#ifndef WALLS_H_
#define WALLS_H_

#include "HitBox.h"
#include "Collisional.h"
#include "Drawable.h"

/**
 * Dolna ściana uniemożliwiająca opuszczenie
 * przez piłkę placu gry.
 */
class BottomWall: public Collisional, public Drawable {
	HitPoints hitpoints;

public:
	BottomWall() :
			hitpoints(0, 800, 550, 600) {
	}

	/**
	 * Ścianie nic nie dzieje się po kolizji z piłką.
	 */
	void collision() {
	}

	virtual void draw(BITMAP *buffer) {
		rectfill(buffer, hitpoints.getLeft(), hitpoints.getTop(), hitpoints.getRight(), hitpoints.getBottom(),
				ColourMaker::GREEN);
	}

	HitPoints& getHitPoints() {
		return hitpoints;
	}
};

#endif /* WALLS_H_ */
