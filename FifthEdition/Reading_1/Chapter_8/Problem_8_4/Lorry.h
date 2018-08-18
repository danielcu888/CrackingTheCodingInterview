/*
 * Lorry.h
 *
 *  Created on: Mar 7, 2012
 *      Author: danielcumberbatch
 */

#ifndef LORRY_H_
#define LORRY_H_

class Lorry : public Vehicle
{
public:
	Lorry(const Ticket& ticket_)
		: Vehicle(ticket_), type(LORRY)
	{}
};

#endif /* LORRY_H_ */
