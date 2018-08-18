/*
 * Respondent.h
 *
 *  Created on: Feb 27, 2012
 *      Author: danielcumberbatch
 */

#ifndef RESPONDENT_H_
#define RESPONDENT_H_

#include "Employee.h"
#include "Level.h"

class Manager;

class Respondent : public Employee
{
public:
	explicit Respondent(const std::string& _name, const std::string& _id)
		: Employee(_name, _id, RESP_LEVEL)
	{}

	bool canTakeCall(const TelephoneCall&) const;
	void dealWithCall(const TelephoneCall&) const;

	Manager *getManager() const {return manager;};

private:
	Manager *manager;
};

#endif /* RESPONDENT_H_ */
