#ifndef GAME_H_
#define GAME_H_

#include <allegro.h>
#include "GameWindow.h"
#include "Drawable.h"
#include "Moveable.h"
#include "Collisional.h"
#include "HitBox.h"
#include "Bonus.h"
#include "RandomUtils.h"
#include <list>
#include <ctime>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

using namespace std;

class Game {
	list<Drawable*> drawables;
	list<Moveable*> moveables;
	list<Collisional*> collisionals;
	GameWindow gameWindow;
	BITMAP *buffer;
	const int TICKS_PER_SECOND;
	const int SKIP_TICKS;
	const int MAX_FRAMESKIP;
	double nextGameTick;
	int loops;

public:
	Game() :
			gameWindow(GFX_AUTODETECT_WINDOWED, SCREEN_WIDTH, SCREEN_HEIGHT),
					TICKS_PER_SECOND(50),
					SKIP_TICKS(150 / TICKS_PER_SECOND),
					MAX_FRAMESKIP(10),
					nextGameTick(getTickCount()) {
		srand(time(0));
		buffer = create_bitmap(SCREEN_WIDTH, SCREEN_HEIGHT);
	}

	double getTickCount() {
		struct timespec now;
		if (clock_gettime(CLOCK_MONOTONIC, &now))
			return 0;
		return now.tv_sec * 1000.0 + now.tv_nsec / 1000000.0;
	}

	void start() {
		gameWindow.open();
		while (!key[KEY_ESC]) {
			loops = 0;
			while (getTickCount() > nextGameTick && loops < MAX_FRAMESKIP) {
				moveMoveables();
				checkCollisions();
				nextGameTick += SKIP_TICKS;
				loops++;
			}
			clear_bitmap(buffer);
			drawDrawables();
			blit(buffer, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
		}
	}

	void addDrawable(Drawable* drawable) {
		drawables.push_back(drawable);
	}

	void addCollisional(Collisional* collisional) {
		collisionals.push_back(collisional);
	}

	void addCollisionals(list<Collisional*> collisionals) {
		for (list<Collisional*>::iterator iterator = collisionals.begin(), end = collisionals.end(); iterator != end;
				++iterator) {
			addCollisional(*iterator);
		}
	}

	void addMoveable(Moveable* moveable) {
		moveables.push_back(moveable);
	}

	virtual ~Game() {
		gameWindow.dispose();
	}
private:

	void checkCollisions() {
		for (list<Collisional*>::iterator iterator = collisionals.begin(), end = collisionals.end(); iterator != end;
				++iterator) {
			Collisional* objectA = (*iterator);
			for (list<Collisional*>::iterator iterator2 = iterator, end = collisionals.end(); iterator2 != end;
					++iterator2) {
				Collisional* objectB = *iterator2;
				if (objectA == objectB) {
					continue;
				}
				if (objectA->getHitPoints().getLeft() <= objectB->getHitPoints().getRight()
						&& objectA->getHitPoints().getRight() >= objectB->getHitPoints().getLeft()
						&& objectA->getHitPoints().getBottom() >= objectB->getHitPoints().getTop()
						&& objectA->getHitPoints().getTop() <= objectB->getHitPoints().getBottom()) {
					objectA->collision();
					objectB->collision();
				}
			}
		}
	}

	void drawDrawables() {
		acquire_screen();
		for (list<Drawable*>::iterator iterator = drawables.begin(), end = drawables.end(); iterator != end;
				++iterator) {
			(*iterator)->draw(buffer);
		}
		release_screen();
	}

	void moveMoveables() {
		for (list<Moveable*>::iterator iterator = moveables.begin(), end = moveables.end(); iterator != end;
				++iterator) {
			(*iterator)->move();
		}
	}
};

#endif /* GAME_H_ */
