/*
 * Caller.h
 *
 *  Created on: Feb 27, 2012
 *      Author: danielcumberbatch
 */

#ifndef CALLER_H_
#define CALLER_H_

#include <string>
#include "Level.h"

struct Caller
{
	std::string name;
	std::string address;
	std::string telephoneNum;
	LEVEL requestLevel;
};

#endif /* CALLER_H_ */
