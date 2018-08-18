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
		: head(NULL), min_head(NULL)
	{}
	~Stack();

	void push(int);
	void pop();
	std::size_t size() const;
	bool empty() const;
	int top() const;
	int min() const;

protected:
	struct Node {
		Node(int data_ = 0, Node *next_ = NULL)
			: data(data_), next(next_)
		{}
		int data;
		Node *next;
	};

private:
	Node *head;
	Node *min_head;
};

#endif /* STACK_H_ */
