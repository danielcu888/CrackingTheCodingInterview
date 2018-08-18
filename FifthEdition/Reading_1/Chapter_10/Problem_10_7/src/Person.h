/*
 * Person.h
 *
 *  Created on: Mar 12, 2012
 *      Author: danielcumberbatch
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <stdexcept>
#include <cstddef>

class Person
{
public:
	explicit Person(std::size_t wt_, size_t ht_) :
		ht(ht_), wt(wt_), available(true)
	{
		if(ht == 0 || wt == 0)
			throw std::out_of_range("");
	}

	bool isAvailable() const {return available;}
	void setAvailability(bool b) {available = b;}

	std::size_t height() const {return ht;}
	std::size_t weight() const {return wt;}

private:
	std::size_t ht, wt;
	bool available;
};


#endif /* PERSON_H_ */
