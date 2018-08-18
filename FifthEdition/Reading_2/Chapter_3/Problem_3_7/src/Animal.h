/*
 * Animal.h
 *
 *  Created on: Mar 19, 2012
 *      Author: danielcumberbatch
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <cstddef>

enum SPECIES {CAT = 0, DOG = 1};

class Animal
{
public:
	explicit Animal(SPECIES s_)
		: s(s_)
	{}
	virtual ~Animal() = 0;

	SPECIES getSpecies() const {return s;}
	std::size_t getOrder() const { return order; }
	void setOrder(std::size_t order_) { order = order_; }

private:
	SPECIES s;
	std::size_t order;
};

class Dog : public Animal
{
public:
	explicit Dog()
		: Animal(DOG)
	{}
};

class Cat : public Animal
{
	explicit Cat()
		: Animal(CAT)
	{}
};

#endif /* ANIMAL_H_ */
