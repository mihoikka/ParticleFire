/*
 * Swarm.cpp
 *
 *  Created on: Jan 20, 2024
 *      Author: mitch
 */

#include "Swarm.h"

namespace mrh {

Swarm::Swarm() {
	// TODO Auto-generated constructor stub
	m_swarm = new Particle[N_PARTICLES];
}

Swarm::~Swarm() {
	// TODO Auto-generated destructor stub
	delete [] m_swarm;
}
void Swarm::updateParticles(){
	for(int i = 0; i < N_PARTICLES; i++){
		m_swarm[i].updatePos();
	}
}
} /* namespace mrh */
