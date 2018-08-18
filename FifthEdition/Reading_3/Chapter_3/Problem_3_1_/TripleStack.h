/*
 * TripleStack.h
 *
 *  Created on: Apr 18, 2012
 *      Author: danielcumberbatch
 */

#ifndef TRIPLESTACK_H_
#define TRIPLESTACK_H_

#include <cstddef>
#include <stdexcept>

class TripleStack
{
public:
	TripleStack(std::size_t stacksize_)
		: STACKSIZE(stacksize_)
	{
		if(stacksize_ == 0)
			throw std::logic_error("Can't intialize zero-sized stacks!");
		fp[0] = fp[1] = fp[2] = NULL;
	}

	void push(std::size_t, int);
	void pop(std::size_t);
	int top(std::size_t) const;
	bool empty(std::size_t) const;
	std::size_t size(std::size_t) const;

private:
	std::size_t STACKSIZE;
	int a[STACKSIZE*3];
	int *fp[3];
};

#endif /* TRIPLESTACK_H_ */
