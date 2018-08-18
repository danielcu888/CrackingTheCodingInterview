/*
 * Director.h
 *
 *  Created on: Feb 27, 2012
 *      Author: danielcumberbatch
 */

#ifndef DIRECTOR_H_
#define DIRECTOR_H_

#include "Employee.h"
#include "Level.h"

class Director : public Employee
{
public:
	explicit Director(const std::string& _name, const std::string& _id)
		: Employee(_name, _id, DIR_LEVEL)
	{}

	bool canTakeCall(const TelephoneCall&) const;
	void dealWithCall(const TelephoneCall&) const;

protected:

private:
};

#endif /* DIRECTOR_H_ */
