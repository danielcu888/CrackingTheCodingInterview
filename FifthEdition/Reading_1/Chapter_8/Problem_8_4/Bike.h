/*
 * Bike.h
 *
 *  Created on: Mar 7, 2012
 *      Author: danielcumberbatch
 */

#ifndef BIKE_H_
#define BIKE_H_

class Bike : public Vehicle
{
public:
	Bike(const Ticket& ticket_)
		: Vehicle(ticket_), type(BIKE)
	{}
};


#endif /* BIKE_H_ */
