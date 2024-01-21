/*
 * Particle.cpp
 *
 *  Created on: Jan 20, 2024
 *      Author: mitch
 */

#include "Particle.h"
#include <iostream>
namespace mrh {

Particle::Particle() {
	/*m_x = (2.0*rand()/RAND_MAX)-1;
	m_y = (2.0*rand()/RAND_MAX)-1;*/
	//m_x = (1.0*rand())/RAND_MAX;
	//m_y = (1.0*rand())/RAND_MAX;
	m_xpos = (1.0*rand())/RAND_MAX*SDL_SCREEN_WIDTH;
	m_ypos = (1.0*rand())/RAND_MAX*SDL_SCREEN_HEIGHT;
	m_xvelocity = (1.0*rand())/RAND_MAX;
	m_yvelocity = (1.0*rand())/RAND_MAX;
	// TODO Auto-generated constructor stub

}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle::updatePos(){
	m_xpos += m_xvelocity;
	m_ypos += m_yvelocity;
	if(m_xpos >= SDL_SCREEN_WIDTH || m_xpos <= 0 ){
		m_xvelocity *= -1;
		m_xpos += m_xvelocity;
	}
	if(m_ypos >= SDL_SCREEN_HEIGHT || m_ypos <= 0 ){
		m_yvelocity *= -1;
		m_ypos += m_yvelocity;
	}

	m_xvelocity += ((1.0*rand())/RAND_MAX)-0.5;
	m_yvelocity += ((1.0*rand())/RAND_MAX)-0.5;
}
} /* namespace mrh */
