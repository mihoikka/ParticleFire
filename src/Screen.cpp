/*
 * Screen.cpp
 *
 *  Created on: Jan 15, 2024
 *      Author: mitch
 */

#include "Screen.h"

namespace mrh {

Screen::Screen():
		m_window(NULL),
		m_renderer(NULL),
		m_texture(NULL),
		m_buffer(NULL) {
	// TODO Auto-generated constructor stub
}

Screen::~Screen(){
	// TODO Auto-generated destructor stub
}


bool Screen::init(){

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		return false;
		//return 1;
	}
	m_window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SDL_SCREEN_WIDTH, SDL_SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if(m_window == NULL){
		std::cout << SDL_GetError() << std::endl;;
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (m_renderer == NULL){
		std::cout<<"Could not create renderer"<<std::endl;
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SDL_SCREEN_WIDTH, SDL_SCREEN_HEIGHT);
	if (m_texture == NULL){
			std::cout<<"Could not create texture"<<std::endl;
			SDL_DestroyWindow(m_window);
			SDL_DestroyRenderer(m_renderer);
			SDL_Quit();
			return false;
		}
	m_buffer = new Uint32[SDL_SCREEN_WIDTH*SDL_SCREEN_HEIGHT];
	//memset(m_buffer, 255, SDL_SCREEN_WIDTH*SDL_SCREEN_HEIGHT*sizeof(Uint32));
	//m_buffer[30000] = 0xFFFFFFFF;
/*	for(int i = 0; i < SDL_SCREEN_WIDTH*SDL_SCREEN_HEIGHT;i++){
		m_buffer[i] = 0xFFFFFF00;
	}*/
	for(int x = 0; x < SDL_SCREEN_WIDTH; ++x){
		for(int y = 0; y < SDL_SCREEN_HEIGHT; ++y){
			setPixel(x, y, 255, 255, 255, 255);
		}
	}
	update();

	return true;

}
bool Screen::processEvents(){
	SDL_Event event;
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT){
			return false;
		}
	}
	return true;

}
void Screen::close(){

	delete [] m_buffer;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);

	SDL_Quit();

}
void Screen::update(){
	SDL_UpdateTexture(m_texture, NULL, m_buffer, SDL_SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}
void Screen::setPixel(int x, int y, Uint8 alpha, Uint8 red, Uint8 green, Uint8 blue){
	Uint32 color = 0;

	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += alpha;

	m_buffer[y*SDL_SCREEN_WIDTH+x] = color;
}
} /* namespace mrh */
