/*
 * StackWithMin.hpp
 *
 *  Created on: Jan 2, 2012
 *      Author: danielcumberbatch
 */

#ifndef STACKWITHMIN_HPP_
#define STACKWITHMIN_HPP_

#include <stack>
#include <cstddef>

class StackWithMin
{
public:
	bool empty() const;
	std::size_t size() const;

	int top() const;

	void push(int);
	void pop();

	int min() const;

private:
	std::stack<int> items;
	std::stack<int> mins;
};

#endif /* STACKWITHMIN_HPP_ */
