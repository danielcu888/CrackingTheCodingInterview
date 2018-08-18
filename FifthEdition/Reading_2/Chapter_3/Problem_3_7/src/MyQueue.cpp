/*
 * MyQueue.cpp
 *
 *  Created on: Mar 19, 2012
 *      Author: danielcumberbatch
 */

#include "MyQueue.h"
#include "Animal.h"
#include <stdexcept>

using std::logic_error;

void MyQueue::push(Animal* a)
{
	a->setOrder(counter++);
	if(a->getSpecies() == DOG)
		dogQueue.push(static_cast<Dog*>(a));
	else
		catQueue.push(static_cast<Cat*>(a));
}

Animal *MyQueue::pop()
{
	if(dogQueue.empty() && catQueue.empty())
		throw logic_error("pop: Queues empty!");
	if(catQueue.empty() || dogQueue.front()->getOrder() < catQueue.front()->getOrder())
		return popDog();
	else
		return popCat();
}

Dog *MyQueue::popDog()
{
	if(dogQueue.empty())
		throw logic_error("popDog: Queue empty!");
	Dog *ret = dogQueue.front();
	dogQueue.pop();
	return ret;
}

Cat *MyQueue::popCat()
{
	if(catQueue.empty())
		throw logic_error("popCat: Queue empty!");
	Cat *ret = catQueue.front();
	catQueue.pop();
	return ret;
}

