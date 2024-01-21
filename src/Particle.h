/*
 * Particle.h
 *
 *  Created on: Jan 20, 2024
 *      Author: mitch
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <stdlib.h>

namespace mrh {

struct Particle {
private:
	double m_xvelocity;
	double m_yvelocity;
	const static int SDL_SCREEN_WIDTH = 800;
	const static int SDL_SCREEN_HEIGHT = 600;
public:
	//double m_x;
	//double m_y;
	int m_xpos;
	int m_ypos;
	void updatePos();

	Particle();
	virtual ~Particle();
};

} /* namespace mrh */

#endif /* PARTICLE_H_ */
