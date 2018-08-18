/*
 * MyQueue.h
 *
 *  Created on: Mar 19, 2012
 *      Author: danielcumberbatch
 */

#ifndef MYQUEUE_H_
#define MYQUEUE_H_

#include <queue>
#include "Animal.h"

class MyQueue
{
public:
	explicit MyQueue() : counter(0) {}

	void push(Animal*);
	Animal* pop();
	Dog* popDog();
	Cat* popCat();

private:
	std::size_t counter;
	std::queue<Cat*> catQueue;
	std::queue<Dog*> dogQueue;
};

#endif /* MYQUEUE_H_ */
