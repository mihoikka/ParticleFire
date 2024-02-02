/*
 * Particle.cpp
 *
 *  Created on: Jan 20, 2024
 *      Author: mitch
 */

#include "Particle.h"
#include <math.h>
#include <iostream>
namespace mrh {

Particle::Particle(): m_xpos(SDL_SCREEN_WIDTH/2), m_ypos(SDL_SCREEN_HEIGHT/2) {
	m_direction = (2.0 * M_PI * rand())/RAND_MAX;
	m_speed = (0.04 * rand())/RAND_MAX;
	m_speed *= m_speed;
	m_int_xpos = (int)m_xpos;
	m_int_ypos = (int)m_ypos;
}
void Particle::reInit(){
	m_direction = (2.0 * M_PI * rand())/RAND_MAX;
	m_speed = (0.04 * rand())/RAND_MAX;
	m_speed *= m_speed;
	m_xpos = SDL_SCREEN_WIDTH/2;
	m_ypos = SDL_SCREEN_HEIGHT/2;
	m_int_xpos = (int)(m_xpos);
	m_int_ypos = (int)(m_ypos);
}
Particle::~Particle() {
}

void Particle::updatePos(int interval){
	m_direction += interval*.0003;
	double x_speed = m_speed * cos(m_direction);
	double y_speed = m_speed * sin(m_direction);
	m_xpos += (x_speed * SDL_SCREEN_WIDTH * interval);
	m_ypos += (y_speed * SDL_SCREEN_WIDTH * interval);
	m_int_xpos = (int)m_xpos;
	m_int_ypos = (int)m_ypos;

	if (m_int_xpos < 0 || m_int_xpos >= SDL_SCREEN_WIDTH || m_int_ypos < 0 || m_int_ypos >= SDL_SCREEN_HEIGHT ){
		reInit();
	}
	if ( rand() < RAND_MAX/100){
		reInit();
	}
}
} /* namespace mrh */
