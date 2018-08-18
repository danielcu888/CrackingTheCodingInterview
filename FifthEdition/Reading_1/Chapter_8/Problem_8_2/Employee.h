/*
 * Employee.h
 *
 *  Created on: Feb 27, 2012
 *      Author: danielcumberbatch
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <string>
#include "TelephoneCall.h"
#include "Level.h"

class Uncopyable
{
protected:
	Uncopyable() {}
	~Uncopyable() {}

private:
	Uncopyable(const Uncopyable&);
	Uncopyable& operator=(const Uncopyable&);
};

class Employee : private Uncopyable
{
public:
	explicit Employee(const std::string& _name, const std::string& _id, LEVEL l)
		: level(l), name(_name), id(_id), available(true)
	{}

	virtual ~Employee() {}

	bool isAvailable() const {return available;}
	void setAvailability(bool b) {available = b;}

	virtual bool canTakeCall(const TelephoneCall&) const = 0; //if all available employees of a specific strata
	virtual void dealWithCall(const TelephoneCall&) const = 0;

	const LEVEL getLevel() const {return level;}

	void setTelephoneCall(const TelephoneCall& tc) {call = tc;}
	const TelephoneCall getTelephoneCall() const {return call;}

	void finishCall() {setAvailability(true);}

protected:
	LEVEL level; //indicates level of employee 0 = respondent, 1 = Manager, 2 = Director, set in derived class constructors

private:
	std::string name;
	std::string id;
	bool available;
	TelephoneCall call;
};


#endif /* EMPLOYEE_H_ */
