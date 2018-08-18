/*
 * Vehicle.h
 *
 *  Created on: Mar 7, 2012
 *      Author: danielcumberbatch
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_

#include "Ticket.h"

enum VEHICLE_TYPE {BIKE, CAR, LORRY};

class Vehicle
{
public:
	Vehicle(const Ticket& ticket_)
		: ticket(ticket_)
	{}

	virtual ~Vehicle() = 0;
	const Ticket& getTicket() const {return ticket;}
	const VEHICLE_TYPE getType() const {return type;}

protected:
	VEHICLE_TYPE type;

private:
	Ticket ticket;
};

#endif /* VEHICLE_H_ */
