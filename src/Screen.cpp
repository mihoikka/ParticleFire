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
		std::cout << SDL_GetError();
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
	m_buffer_blur = new Uint32[SDL_SCREEN_WIDTH*SDL_SCREEN_HEIGHT];

	return true;
}

bool Screen::processEvents(){
	SDL_Event event;
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT){
			return false;
		}
	}

	int elapsed = SDL_GetTicks();
	unsigned char red = (unsigned char)((1 + sin(elapsed*.0002)) * 128);
	unsigned char green = (unsigned char)((1 + sin(elapsed*.0001)) * 128);
	unsigned char blue = (unsigned char)((1 + sin(elapsed*.0003)) * 128);

	//for ( auto particle : *swarm){
	Particle *particles = swarm.getParticles();
	Particle *particle;
	/*for(int i = 0; i < swarm.N_PARTICLES; i++){
		particle = &(particles[i]);
		setPixel(particle->m_xpos, particle->m_ypos, 0, 0, 0, 255);
	}*/
	//clear();
	swarm.updateParticles(elapsed);
	for(int i = 0; i < swarm.N_PARTICLES; i++){
		particle = &(particles[i]);
		setPixel(particle->m_xpos, particle->m_ypos, red, green, blue, 255);
	}
	boxBlur();
	update();
	//SDL_Delay(.1);

	return true;

}
void Screen::close(){

	delete [] m_buffer;
	delete [] m_buffer_blur;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit();

}
void Screen::update(){
	SDL_UpdateTexture(m_texture, NULL, m_buffer_blur, SDL_SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
}
void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha){
	if (!(x >= 0 && x < SDL_SCREEN_WIDTH && y >= 0 && y < SDL_SCREEN_HEIGHT)){
		return;
	}
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

Uint32 Screen::getPixel(int pixelX, int pixelY, int componentRequested){
	switch(componentRequested){
	case 1:
		return (0xFF000000 & m_buffer[pixelY*SDL_SCREEN_WIDTH+pixelX])>>24;
	case 2:
		return (0xFF000000 & m_buffer[pixelY*SDL_SCREEN_WIDTH+pixelX])>>16;

	case 3:
		return (0xFF000000 & m_buffer[pixelY*SDL_SCREEN_WIDTH+pixelX])>>8;

	case 4:
		return (0xFF000000 & m_buffer[pixelY*SDL_SCREEN_WIDTH+pixelX]);
	}
	return (Uint32)-1;
}

void Screen::boxBlur(){
	Uint32 *temp = m_buffer;


	for(int y = 0; y < SDL_SCREEN_HEIGHT; y++){
			for(int x = 0; x < SDL_SCREEN_WIDTH; x++){
				int redTotal = 0;
				int greenTotal = 0;
				int blueTotal = 0;
				for(int centered_col = -1; centered_col <= 1; centered_col++){
					for(int centered_row = -1; centered_row <= 1 ; centered_row++){
						int currX = x + centered_row;
						int currY = y + centered_col;
						if (currY >= 0 && currY < SDL_SCREEN_HEIGHT && currX >= 0 && currX < SDL_SCREEN_WIDTH){
							Uint32 currColor = m_buffer[currY*SDL_SCREEN_WIDTH+currX];
							redTotal += (0xFF000000 & currColor)>>24;
							greenTotal += (0x00FF0000 & currColor)>>16;
							blueTotal += (0x0000FF00 & currColor)>>8;
						}
					}
				}
				Uint8 red_blurred = (int)(redTotal/9);
				Uint8 green_blurred = (int)(greenTotal/9);
				Uint8 blue_blurred = (int)(blueTotal/9);
				setPixel(x,y,red_blurred,green_blurred,blue_blurred, 255);
			}
		}
	//m_buffer = m_buffer_blur;
	m_buffer_blur = temp;
}

void Screen::clear(){
	memset(m_buffer, 0, SDL_SCREEN_WIDTH*SDL_SCREEN_HEIGHT * sizeof(Uint32));
	memset(m_buffer_blur, 0, SDL_SCREEN_WIDTH*SDL_SCREEN_HEIGHT * sizeof(Uint32));
}
} /* namespace mrh */
