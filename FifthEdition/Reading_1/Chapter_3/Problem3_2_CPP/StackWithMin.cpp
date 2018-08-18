/*
 * StackWithMin.cpp
 *
 *  Created on: Jan 2, 2012
 *      Author: danielcumberbatch
 */

#include "StackWithMin.hpp"
#include <cstddef>
#include <stdexcept>

using std::size_t;
using std::logic_error;

bool StackWithMin::empty() const
{
	return items.empty();
}

size_t StackWithMin::size() const
{
	return items.size();
}

int StackWithMin::top() const
{
	return items.top();
}

void StackWithMin::push(int val)
{
	if(items.empty() || val <= mins.top())
		mins.push(val);
	items.push(val);
}

void StackWithMin::pop()
{
	if(items.empty())
		throw logic_error("Attempt to pop an empty stack!");
	if(items.top() == mins.top())
		mins.pop();
}

int StackWithMin::min() const
{
	return mins.top();
}



