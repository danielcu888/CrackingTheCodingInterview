/*
 * CallHandler.h
 *
 *  Created on: Feb 27, 2012
 *      Author: danielcumberbatch
 */

#ifndef CALLHANDLER_H_
#define CALLHANDLER_H_

#include <queue>
#include "TelephoneCall.h"
#include <stdexcept>
#include <vector>
#include "Employee.h"
#include <cstddef>

class CallHandler
{
public:
	CallHandler static getInstance()
	{
		if(!this)
			return CallHandler();
		return *this;
	}

	Employee* getAvailableEmployee(const TelephoneCall& tc)
	{
		for(std::vector<std::vector<Employee*> >::size_type i = 0; i != staff.size(); ++i)
			for(std::vector<Employee*>::size_type j = 0; j != staff[i].size(); ++j)
				if(tc.getRequestLevel() >= staff[i][j]->getLevel() && staff[i][j]->isAvailable())
					return staff[i][j];
		return NULL;
	}

	void displatchCall(const TelephoneCall& tc)
	{
		Employee *tmp = getAvailableEmployee(tc);
		if(!tmp)
		{
			switch(tc.getRequestLevel())
			{
			case RESP_LEVEL:
				calls[0].push(tc);
				return;
			case MAN_LEVEL:
				calls[1].push(tc);
				return;
			case DIR_LEVEL:
				calls[2].push(tc);
				return;
			default:
				return;
			}
		}
		tmp->dealWithCall(tc);
	}

	void assignCall(Employee* emp)
	{
		if(!emp->isAvailable()) return;

		switch(emp->getLevel())
		{
		case RESP_LEVEL:
			if(!calls[0].empty())
			{
				emp->dealWithCall(calls[0].front());
				calls[0].pop();
			}
			return;
		case MAN_LEVEL:
			if(!calls[1].empty())
			{
				emp->dealWithCall(calls[1].front());
				calls[1].pop();
			}

			return;
		case DIR_LEVEL:
			if(!calls[2].empty())
			{
				emp->dealWithCall(calls[2].front());
				calls[2].pop();
			}
			return;
		default:
			return;
		}
	}

private:
	CallHandler() {}

	const std::size_t NUM_LEVELS = 3;

	const std::size_t NUM_RESP = 10;
	const std::size_t NUM_MAN = 4;
	const std::size_t NUM_DIR = 2;

	/*
	 * staff[0] = respondents
	 * staff[1] = managers
	 * staff[2] = directors
	 */
	std::vector<std::vector<Employee*> > staff;

	std::vector<std::queue<TelephoneCall> > calls;
};

#endif /* CALLHANDLER_H_ */
