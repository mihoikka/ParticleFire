/*
 * Swarm.h
 *
 *  Created on: Jan 20, 2024
 *      Author: mitch
 */

#ifndef SWARM_H_
#define SWARM_H_
#include "Particle.h"

namespace mrh {

class Swarm {
public:
	const static int N_PARTICLES = 1000;
private:
	Particle * m_swarm;
public:
	Swarm();
	virtual ~Swarm();
	//const Particle * const getParticles(){
	Particle * getParticles(){
		return m_swarm;
	}
	Particle *begin(){return m_swarm;};
	Particle *end(){ return m_swarm + N_PARTICLES;};
	void updateParticles();

};

} /* namespace mrh */

#endif /* SWARM_H_ */
