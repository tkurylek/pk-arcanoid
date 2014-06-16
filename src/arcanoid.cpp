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

	Level* levels[] = {
			new LevelOne(),
			new LevelTwo(),
			new LevelThree(),
			new LevelFour()
	};
	int levelIndex = RandomUtils::randomInt(0, 3);
	game->addDrawable(levels[levelIndex]);
	game->addCollisionals(levels[levelIndex]->getBricks());

	Ball* ball = new Ball(300, 200);
	game->addDrawable(ball);
	game->addMoveable(ball);
	game->addCollisional(ball);

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
	try {
		game->start();
	} catch (AllegroInitalizationException &e) {
		cout << "Nie można uruchomić biblioteki Allegro" << endl;
	} catch (GameOverException &e) {
		cout << "Koniec gry. " << e.what() << endl;
	}
	for (int i = 0; i < numberOfBonuses; i++) {
		delete bonuses[i];
	}
	delete paddle;
	delete ball;
	delete game;
	return 0;
}
