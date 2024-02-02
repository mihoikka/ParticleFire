/*
 * Swarm.cpp
 *
 *  Created on: Jan 20, 2024
 *      Author: mitch
 */

#include "Swarm.h"
#include <iostream>

namespace mrh {

Swarm::Swarm():lastTime(0) {
	m_swarm = new Particle[N_PARTICLES];
}

Swarm::~Swarm() {
	delete [] m_swarm;
}
void Swarm::updateParticles(int elapsed){
	int interval = elapsed - lastTime;
	lastTime = elapsed;
    /*std::cout<<"Elapsed time in ms: " << elapsed<<std::endl;
	std::cout<<"Interval between frames in ms: " << interval<<std::endl;*/
	for(int i = 0; i < N_PARTICLES; i++){
		m_swarm[i].updatePos(interval);
	}
}
} /* namespace mrh */
