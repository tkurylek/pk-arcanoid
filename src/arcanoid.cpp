#include <iostream>
#include "Game.h"
#include "Paddle.h"
#include "Ball.h"
#include "Walls.h"

using namespace std;

int main() {
	Game game = Game();
	Paddle* paddle = new Paddle();

	for (int i = 1; i < 5; i++) {
		Ball* ball = new Ball(i * 100, i * 100);
		game.addDrawable(ball);
		game.addMoveable(ball);
		game.addCollisional(ball);
	}

	game.addCollisional(new LeftWall());
	game.addCollisional(new RightWall());
	game.addCollisional(new TopWall());
	game.addCollisional(new BottomWall());

	game.addDrawable(paddle);
	game.addMoveable(paddle);
	game.addCollisional(paddle);

	game.start();
	delete paddle;
	return 0;
}
