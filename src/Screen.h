/*
 * Screen.h
 *
 *  Created on: Jan 15, 2024
 *      Author: mitch
 */

#ifndef SCREEN_H_
#define SCREEN_H_
#include <iostream>
#include <SDL.h>

namespace mrh {

class Screen {
private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer;
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


};

} /* namespace mrh */

#endif /* SCREEN_H_ */
