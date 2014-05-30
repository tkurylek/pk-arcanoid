#ifndef LEVEL_H_
#define LEVEL_H_

#include <list>
#include "Drawable.h"
#include "Collisional.h"
#include "Brick.h"

using namespace std;

class BrickWall: public Drawable {

	list<Brick*> bricks;

public:
	BrickWall(int width, int height) {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				bricks.push_back(new Brick(80+i * 104, 50+j * 25));
			}
		}
	}

	void draw(BITMAP *buffer) {
		drawAllBricks(buffer);
	}

	list<Collisional*> getBricks() {
		list<Collisional*> l;
		for (list<Brick*>::iterator iterator = bricks.begin(), end = bricks.end(); iterator != end;
				++iterator) {
			l.push_back((*iterator));
		}
		return l;
	}

	~BrickWall() {
		while (!bricks.empty()) {
			delete bricks.front(), bricks.pop_front();
		}
	}

private:
	inline void drawAllBricks(BITMAP *buffer) {
		for (list<Brick*>::iterator iterator = bricks.begin(), end = bricks.end(); iterator != end;
				++iterator) {
			(*iterator)->draw(buffer);
		}
	}
};
#endif /* LEVEL_H_ */
