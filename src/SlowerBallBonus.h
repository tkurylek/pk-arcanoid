#ifndef SLOWERBALLBONUS_H_
#define SLOWERBALLBONUS_H_

/**
 * A bonus that adds another ball to the game.
 */
class SlowerBallBonus: public Bonus {

	Ball* ball;

public:

	SlowerBallBonus(Ball* ball) :
			Bonus() {
		this->ball = ball;
	}

	void activate() {
		ball->speedDown(.5);
	}
};

#endif /* SLOWERBALLBONUS_H_ */
