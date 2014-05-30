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

	Bonus* bottomWallBonus = new BottomWallBonus(game);
	game->addBonus(bottomWallBonus);

	Bonus* additionalBallBonus = new AdditionalBallBonus(game);
	game->addBonus(additionalBallBonus);

	Bonus* blackHoleBonus = new BlackHoleBonus(ball);
	game->addBonus(blackHoleBonus);

	Bonus* shorterPaddleBonus = new ShorterPaddleBonus(paddle);
	game->addBonus(shorterPaddleBonus);

	Bonus* widerPaddleBonus = new WiderPaddleBonus(paddle);
	game->addBonus(widerPaddleBonus);

	Bonus* slowerBallBonus = new SlowerBallBonus(ball);
	game->addBonus(slowerBallBonus);

	game->start();

	delete slowerBallBonus;
	delete widerPaddleBonus;
	delete shorterPaddleBonus;
	delete blackHoleBonus;
	delete additionalBallBonus;
	delete bottomWallBonus;
	delete paddle;
	delete topWall;
	delete rightWall;
	delete leftWall;
	delete ball;
	delete simpleBrickWall;
	delete game;

	return 0;
}
