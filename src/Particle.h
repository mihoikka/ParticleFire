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
	double m_speed;
	double m_direction;
	const static int SDL_SCREEN_WIDTH = 800;
	const static int SDL_SCREEN_HEIGHT = 600;
private:
	void reInit();
public:
	double m_xpos;
	double m_ypos;
	int m_int_xpos;
	int m_int_ypos;
	void updatePos(int interval);

	Particle();
	virtual ~Particle();
};

} /* namespace mrh */

#endif /* PARTICLE_H_ */
