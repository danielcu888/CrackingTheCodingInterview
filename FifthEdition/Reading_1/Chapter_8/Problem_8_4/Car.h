/*
 * Car.h
 *
 *  Created on: Mar 7, 2012
 *      Author: danielcumberbatch
 */

#ifndef CAR_H_
#define CAR_H_

class Car : public Vehicle
{
public:
	Car(const Ticket& ticket_)
		: Vehicle(ticket_), type(CAR)
	{}
};


#endif /* CAR_H_ */
