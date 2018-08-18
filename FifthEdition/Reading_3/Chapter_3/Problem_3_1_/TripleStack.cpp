/*
 * TripleStack.cpp
 *
 *  Created on: Apr 18, 2012
 *      Author: danielcumberbatch
 */

#include "TripleStack.h"
#include <cstddef>
#include <stdexcept>

using std::size_t; using std::out_of_range;
using std::logic_error;

void TripleStack::push(size_t idx, int d)
{
	if(idx > 2 || idx < 0)
		throw out_of_range("idx out of range!");
	if(fp[idx] - a >= STACKSIZE + idx*STACKSIZE)
		throw logic_error("Stack Full!");
	*fp[idx] = d;
	++fp[idx];
}

void TripleStack::pop(std::size_t idx)
{
	if(idx > 2 || idx < 0)
		throw out_of_range("idx out of range!");
	if(fp[idx] - a == idx*STACKSIZE)
		throw logic_error("Stack Empty!");
	--fp[idx];
}

int TripleStack::top(std::size_t idx) const
{
	if(idx > 2 || idx < 0)
		throw out_of_range("idx out of range!");
	if(fp[idx] - a == idx*STACKSIZE)
		throw logic_error("Stack Empty!");
	return *fp[idx];
}

bool TripleStack::empty(std::size_t idx) const
{
	if(idx > 2 || idx < 0)
		throw out_of_range("idx out of range!");
	return fp[idx] - a == idx*STACKSIZE;
}

std::size_t TripleStack::size(std::size_t idx) const
{
	if(idx > 2 || idx < 0)
		throw out_of_range("idx out of range!");
	return fp[idx] - (a + idx*STACKSIZE);
}


