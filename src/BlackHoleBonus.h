#ifndef BLACKHOLEBONUS_H_
#define BLACKHOLEBONUS_H_

#include "Bonus.h"
#include "Ball.h"
#include "RandomUtils.h"

/**
 * A bonus that teleports the ball to random position.
 */
class BlackHoleBonus: public Bonus {

	Ball* ball;

public:
	BlackHoleBonus(Ball* ball) :
			Bonus() {
		this->ball = ball;
	}

	void activate() {
		ball->move(RandomUtils::randomInt(50, 500), RandomUtils::randomInt(300, 400));
	}
};

#endif /* BLACKHOLEBONUS_H_ */
