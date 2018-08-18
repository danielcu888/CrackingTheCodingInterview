/*
 * CarSpace.h
 *
 *  Created on: Mar 7, 2012
 *      Author: danielcumberbatch
 */

#ifndef CARSPACE_H_
#define CARSPACE_H_

#include "Space.h"

class CarSpace : public Space
{
public:
	CarSpace(std::size_t loc_id_, std::size_t level_)
		: Space(loc_id, level_), type(CARSPACE)
	{}

};

#endif /* CARSPACE_H_ */
