#ifndef LEVEL_H_
#define LEVEL_H_

#include <list>
#include "Drawable.h"
#include "Collisional.h"
#include "Brick.h"
#include "GameOverException.h"

using namespace std;

class Level: public Drawable {
protected:
	int numberOfBricks;
	list<Brick*> bricks;

public:

	void draw(BITMAP *buffer) {
		drawAllBricks(buffer);
	}

	inline void drawAllBricks(BITMAP *buffer) {
		int numberOfHitBricks = 0;
		for (list<Brick*>::iterator iterator = bricks.begin(), end = bricks.end(); iterator != end;
				++iterator) {
			(*iterator)->draw(buffer);
			(*iterator)->getColourByHardness();
			if ((*iterator)->getHardness() <= 0) {
				numberOfHitBricks++;
			}
		}
		checkForGameOver(numberOfHitBricks);
	}

	void checkForGameOver(int numberOfHitBricks) {
		if (numberOfHitBricks >= numberOfBricks) {
			throw GameOverException("Gratulacje, wygrałeś! Dziękuję za grę.");
		}
	}

	list<Collisional*> getBricks() {
		list<Collisional*> l;
		for (list<Brick*>::iterator iterator = bricks.begin(), end = bricks.end(); iterator != end;
				++iterator) {
			l.push_back((*iterator));
		}
		return l;
	}

	virtual ~Level() {
		while (!bricks.empty()) {
			delete bricks.front(), bricks.pop_front();
		}
	}
};

class LevelOne: public Level {

public:
	LevelOne(int width = 6, int height = 4) :
			Level() {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				bricks.push_back(new Brick(80 + i * 104, 50 + j * 25, 1));
				numberOfBricks++;
			}
		}
	}
};

class LevelTwo: public Level {

public:
	LevelTwo(int width = 7, int height = 5) :
			Level() {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				if (i % 3 + j % 3 > 0) {
					bricks.push_back(new Brick(40 + i * 104, 50 + j * 25, i % 3 + j % 3));
					numberOfBricks++;
				}
			}
		}
	}
};

class LevelThree: public Level {

public:
	LevelThree(int width = 7, int height = 5) :
			Level() {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				if (i % 2 + j % 2 > 0) {
					bricks.push_back(new Brick(40 + i * 104, 50 + j * 25, i % 2 + j % 2));
					numberOfBricks++;
				}
			}
		}
	}
};

class LevelFour: public Level {

public:
	LevelFour(int width = 7, int height = 5) :
			Level() {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				if ((j * i) % 6 > 0) {
					bricks.push_back(new Brick(40 + i * 104, 50 + j * 25, (j * i) % 6));
					numberOfBricks++;
				}
			}
		}
	}
};
#endif /* LEVEL_H_ */
