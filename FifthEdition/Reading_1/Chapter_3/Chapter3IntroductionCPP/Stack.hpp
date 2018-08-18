/*
 * Stack.hpp
 *
 *  Created on: Dec 29, 2011
 *      Author: danielcumberbatch
 */

#ifndef STACK_HPP_
#define STACK_HPP_

#include <cstddef>

class Stack
{
protected:
	struct Node
	{
		Node(void* d) :
			data(d), next(0)
		{}

		void *data;
		Node *next;
	};

public:
	Stack()
	: head(0)
	{}
	~Stack();

	bool empty() const;
	std::size_t size() const;

	const void* top() const;

	void push(void*);
	void pop();

private:
	Node *head;
};

#endif /* STACK_HPP_ */
