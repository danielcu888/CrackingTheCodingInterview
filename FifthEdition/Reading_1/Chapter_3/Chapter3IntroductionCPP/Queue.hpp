/*
 * Queue.hpp
 *
 *  Created on: Dec 29, 2011
 *      Author: danielcumberbatch
 */

#ifndef QUEUE_HPP_
#define QUEUE_HPP_

class Queue
{
protected:
	struct Node
	{
		Node(void *d)
		: data(d), next(0)
		{}

		void *data;
		Node *next;
	};

public:
	Queue();
	~Queue();

	bool empty() const;

	const void* front() const;
	const void* back() const;

	void push(void*);
	void pop();

private:
	Node *head, *tail;
};


#endif /* QUEUE_HPP_ */
