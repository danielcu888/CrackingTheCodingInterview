/*
 * Person.h
 *
 *  Created on: Mar 6, 2012
 *      Author: danielcumberbatch
 */

#ifndef PERSON_H_
#define PERSON_H_

struct Person
{
	Person(unsigned int age_ = 0)
		: age(age_)
	{}

	unsigned int age;
};

#endif /* PERSON_H_ */
