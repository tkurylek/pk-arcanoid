#ifndef GAME_H_
#define GAME_H_

#include <allegro.h>
#include "GameWindow.h"
#include "Drawable.h"
#include "Moveable.h"
#include "Collisional.h"
#include "HitBox.h"
#include <list>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

using namespace std;

class Game {
	list<Drawable*> drawables;
	list<Moveable*> moveables;
	list<Collisional*> collisionals;
	GameWindow gameWindow;
	BITMAP *buffer;

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
public:
	Game() :
			gameWindow(GFX_AUTODETECT_WINDOWED, SCREEN_WIDTH, SCREEN_HEIGHT) {
		buffer = create_bitmap(SCREEN_WIDTH, SCREEN_HEIGHT);
	}

	void start() {
		gameWindow.open();
		while (!key[KEY_ESC]) {
			// logic
			moveMoveables();
			checkCollisions();

			// clear buffer
			clear_bitmap(buffer);

			// draw
			drawDrawables();

			// release buffer
			blit(buffer, screen, 0, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
		}
	}

	void addDrawable(Drawable* drawable) {
		drawables.push_back(drawable);
	}

	void addCollisional(Collisional* collisional) {
		collisionals.push_back(collisional);
	}

	void addMoveable(Moveable* moveable) {
		moveables.push_back(moveable);
	}

	virtual ~Game() {
		gameWindow.dispose();
	}
}
;

#endif /* GAME_H_ */
