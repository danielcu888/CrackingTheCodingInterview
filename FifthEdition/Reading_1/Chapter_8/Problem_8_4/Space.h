/*
 * Space.h
 *
 *  Created on: Mar 7, 2012
 *      Author: danielcumberbatch
 */

#ifndef SPACE_H_
#define SPACE_H_

#include <cstddef>

class Vehicle;

enum SPACE_TYPE {CARSPACE, LORRYSPACE};

class Space
{
public:
	Space(std::size_t loc_id_, std::size_t level_)
		: occupied(false), loc_id(loc_id), level(level_)
	{}

	virtual ~Space() = 0;

	virtual SPACE_TYPE size() const {return type;}
	bool isAvailable() const { return occupied; }
	void setAvailability(bool b) {occupied = b;}

	Vehicle *getVehicle() {return vehicle;}

	std::size_t getLevel() const {return level;}

protected:
	SPACE_TYPE type;

private:
	bool occupied;
	Vehicle *vehicle;
	std::size_t loc_id;
	std::size_t level;
};

#endif /* SPACE_H_ */
