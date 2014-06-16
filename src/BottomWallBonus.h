#ifndef BOTTOMWALLBONUS_H_
#define BOTTOMWALLBONUS_H_

#include "TemporaryBonus.h"

/**
 * A bonus that adds bottom wall so the ball cannot escape.
 */
class BottomWallBonus: public TemporaryBonus {

	BottomWall* bottomWall;
	Game* game;

public:

	BottomWallBonus(Game* game) :
		TemporaryBonus() {
		this->bottomWall = new BottomWall();
		this->game = game;
	}

	void activate() {
		game->addCollisional(bottomWall);
		game->addDrawable(bottomWall);
	}

	void deactivate() {
		game->removeCollisional(bottomWall);
		game->removeDrawable(bottomWall);
	}

	~BottomWallBonus() {
		delete bottomWall;
	}
};

#endif /* BOTTOMWALLBONUS_H_ */
