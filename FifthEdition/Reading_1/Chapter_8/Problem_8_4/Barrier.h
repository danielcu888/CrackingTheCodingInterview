/*
 * Barrier.h
 *
 *  Created on: Mar 7, 2012
 *      Author: danielcumberbatch
 */

#ifndef BARRIER_H_
#define BARRIER_H_

#include "Arm.h"

class Barrier
{
public:
	Barrier()
		: arm(new Arm())
	{}

	bool raiseArm() {return arm->raise();}
	bool lowerArm() {return arm->lower();}

private:
	Arm *arm;
};


#endif /* BARRIER_H_ */
