#ifndef BOTTOMWALLBONUS_H_
#define BOTTOMWALLBONUS_H_

/**
 * A bonus that adds bottom wall so the ball cannot escape.
 */
class BottomWallBonus: public Bonus {

	BottomWall* bottomWall;
	Game* game;

public:

	BottomWallBonus(Game* game) :
			Bonus() {
		this->bottomWall = new BottomWall();
		this->game = game;
	}

	void activate() {
		game->addCollisional(bottomWall);
		game->addDrawable(bottomWall);
	}

	~BottomWallBonus() {
		delete bottomWall;
	}
};

#endif /* BOTTOMWALLBONUS_H_ */
