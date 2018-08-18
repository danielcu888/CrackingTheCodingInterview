/*
 * Manager.h
 *
 *  Created on: Feb 27, 2012
 *      Author: danielcumberbatch
 */

#ifndef MANAGER_H_
#define MANAGER_H_

#include "Employee.h"
#include "Respondent.h"
#include <vector>
#include "Level.h"

class Manager : public Employee
{
public:
	explicit Manager(const std::string& _name, const std::string& _id, LEVEL l, const std::vector<Respondent*>& v)
		: Employee(_name, _id, MAN_LEVEL), respondents(v)
	{}

	void addRespondent(Respondent* r)
	{
		respondents.push_back(r);
	}

	bool canTakeCall(const TelephoneCall&) const;
	void dealWithCall(const TelephoneCall&) const;

private:
	std::vector<Respondent*> respondents;
};

#endif /* MANAGER_H_ */
