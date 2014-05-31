#include <iostream>
#include "Game.h"
#include "Paddle.h"
#include "Ball.h"
#include "Walls.h"
#include "BrickWall.h"
#include "WiderPaddleBonus.h"
#include "ShorterPaddleBonus.h"
#include "BlackHoleBonus.h"
#include "AdditionalBallBonus.h"
#include "SlowerBallBonus.h"
#include "BottomWallBonus.h"

using namespace std;

int main() {
	Game *game = new Game();

	BrickWall* simpleBrickWall = new BrickWall(6, 4);
	game->addDrawable(simpleBrickWall);
	game->addCollisionals(simpleBrickWall->getBricks());

	Ball* ball = new Ball(300, 300);
	game->addDrawable(ball);
	game->addMoveable(ball);
	game->addCollisional(ball);

	LeftWall* leftWall = new LeftWall();
	game->addCollisional(leftWall);

	RightWall* rightWall = new RightWall();
	game->addCollisional(rightWall);

	TopWall* topWall = new TopWall();
	game->addCollisional(topWall);

	Paddle* paddle = new Paddle();
	game->addDrawable(paddle);
	game->addMoveable(paddle);
	game->addCollisional(paddle);

	int numberOfBonuses = 6;
	Bonus* bonuses[] = {
			new BottomWallBonus(game),
			new AdditionalBallBonus(game),
			new BlackHoleBonus(ball),
			new ShorterPaddleBonus(paddle),
			new WiderPaddleBonus(paddle),
			new SlowerBallBonus(ball)
	};
	for (int i = 0; i < numberOfBonuses; i++) {
		game->addDrawable(bonuses[i]);
		game->addCollisional(bonuses[i]);
	}

	game->start();

	for (int i = 0; i < numberOfBonuses; i++) {
		delete bonuses[i];
	}
	delete paddle;
	delete topWall;
	delete rightWall;
	delete leftWall;
	delete ball;
	delete simpleBrickWall;
	delete game;
	return 0;
}
