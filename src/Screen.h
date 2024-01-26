/*
 * Screen.h
 *
 *  Created on: Jan 15, 2024
 *      Author: mitch
 */

#ifndef SCREEN_H_
#define SCREEN_H_
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cstring>
#include <SDL.h>

#include "Swarm.h"

namespace mrh {

class Screen {
private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer;
	Uint32 *m_buffer_blur;
	Swarm swarm;
public:
	const static int SDL_SCREEN_WIDTH = 800;
	const static int SDL_SCREEN_HEIGHT = 600;
	Screen();
	virtual ~Screen();
	bool init();
	bool processEvents();
	void close();
	void update();
	void setPixel(int x, int y, Uint8 alpha, Uint8 red, Uint8 green, Uint8 blue);
	Uint32 getPixel(int pixelX, int pixelY, int componentRequested);
	void boxBlur();
	void clear();


};

} /* namespace mrh */

#endif /* SCREEN_H_ */
