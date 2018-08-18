/*
 * LorrySpace.h
 *
 *  Created on: Mar 7, 2012
 *      Author: danielcumberbatch
 */

#ifndef LORRYSPACE_H_
#define LORRYSPACE_H_

#include <cstddef>
#include "Space.h"

class LorrySpace : public Space
{
public:
	LorrySpace(std::size_t loc_id_, std::size_t level_)
		: Space(loc_id, level_), type(LORRYSPACE)
	{}

};

#endif /* LORRYSPACE_H_ */
