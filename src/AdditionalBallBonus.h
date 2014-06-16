#ifndef ADDITIONALBALLBONUS_H_
#define ADDITIONALBALLBONUS_H_

#include "Bonus.h"
#include "Game.h"

/**
 * Bonus dodający dodatkową piłkę do gry.
 */
class AdditionalBallBonus: public Bonus {

	Game* game;
	list<Ball*> balls;

public:

	AdditionalBallBonus(Game* game) :
			Bonus() {
		this->game = game;
	}

	void activate() {
		Ball* ball = new Ball();
		game->addCollisional(ball);
		game->addDrawable(ball);
		game->addMoveable(ball);
		balls.push_back(ball);
	}

	~AdditionalBallBonus() {
		while (!balls.empty()) {
			delete balls.front(), balls.pop_front();
		}
	}
};

#endif /* ADDITIONALBALLBONUS_H_ */
