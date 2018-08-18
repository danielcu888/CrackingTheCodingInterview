/*
 * Stack.h
 *
 *  Created on: Apr 18, 2012
 *      Author: danielcumberbatch
 */

#ifndef STACK_H_
#define STACK_H_

#include <cstddef>

class Stack
{
public:
	Stack()
		: head(NULL)
	{}
	~Stack();

	int top() const;
	std::size_t size() const;
	void push(int);
	void pop();
	bool empty() const;

protected:
	struct Node {
		Node(int data_ = 0, Node *next_ = 0)
			: data(data_), next(next_)
		{}

		int data;
		Node *next;
	};

private:
	Node *head;
};

#endif /* STACK_H_ */
