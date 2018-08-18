/*
 * TelephoneCall.h
 *
 *  Created on: Feb 27, 2012
 *      Author: danielcumberbatch
 */

#ifndef TELEPHONECALL_H_
#define TELEPHONECALL_H_

#include "Caller.h"
#include "Level.h"

class TelephoneCall
{
public:
	explicit TelephoneCall() {}
	explicit TelephoneCall(const Caller& c)
	{
		if(isValidCaller(c)) caller = c;
	}

	bool isValidCaller(const Caller&) const; //performs checks for wrong numbers, etc.

	LEVEL getRequestLevel() const {return caller.requestLevel;}
	std::string getCallerName() const {return caller.name;}
	std::string getCallerAddress() const {return caller.address;}
	std::string getCallerTelNumber() const {return caller.telephoneNum;}

private:
	Caller caller;
};


#endif /* TELEPHONECALL_H_ */
