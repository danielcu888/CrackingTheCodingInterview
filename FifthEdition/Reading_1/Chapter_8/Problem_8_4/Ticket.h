/*
 * Ticket.h
 *
 *  Created on: Mar 7, 2012
 *      Author: danielcumberbatch
 */

#ifndef TICKET_H_
#define TICKET_H_

#include "Time.h"

class Ticket
{
public:
	Ticket(unsigned long id_, const Time& entryTime_)
		: id(id_), entryTime(entryTime_), validated(false)
	{}

	bool isValidated() const {return validated;}
	void validate() {validated = true;}

private:
	unsigned long id;
	Time entryTime;
	bool validated;
};


#endif /* TICKET_H_ */
