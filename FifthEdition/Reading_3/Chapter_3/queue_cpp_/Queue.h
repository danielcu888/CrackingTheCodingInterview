/*
 * Queue.h
 *
 *  Created on: Apr 18, 2012
 *      Author: danielcumberbatch
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <cstddef>

class Queue
{
public:
	Queue()
		: head(0), tail(0)
	{}

	~Queue();

	void push(int d);
	void pop();
	int front() const;
	int back() const;
	std::size_t size() const;
	bool empty() const;

protected:
	struct Node {
		Node(int data_ = 0, Node *next_ = NULL)
			: data(data_), next(next_)
		{}
		int data;
		Node *next;
	};

private:
	Node *head, *tail;
};

#endif /* QUEUE_H_ */
