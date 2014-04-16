#ifndef ALLEGRO_ADAPTER_H
#define ALLEGRO_ADAPTER_H

#include <allegro.h>
#include "AllegroInitalizationException.h"
#include "ColourMaker.h"

class GameWindow {
	int graphicsMode;
	int width;
	int height;
public:
	GameWindow(int graphicsMode, int width, int height) {
		this->graphicsMode = graphicsMode;
		this->width = width;
		this->height = height;
		if (allegro_init() != 0)
			throw AllegroInitalizationException("Could not initialize allegro library");
	}

	void open() {
		install_keyboard();
		set_color_depth(8);
		set_gfx_mode(graphicsMode, width, height, 0, 0);
		set_palette(default_palette);
	}

	void clear() {
		clear_to_color(screen, ColourMaker::WHITE);
	}

	void wait() {
		rest(1);
	}

	void dispose() {
		allegro_exit();
	}
};

#endif
