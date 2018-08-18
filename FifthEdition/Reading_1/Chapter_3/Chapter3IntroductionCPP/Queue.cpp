/*
 * Queue.cpp
 *
 *  Created on: Dec 29, 2011
 *      Author: danielcumberbatch
 */

#include "Queue.hpp"

Queue::Queue()
: head(0), tail(0)
{}

Queue::~Queue()
{
	while(head)
	{
		Node *tmp = head;
		head = head->next;
		delete tmp;
	}
}

bool Queue::empty() const
{
	return head;
}

const void* Queue::front() const
{
	return head ? head->data : 0;
}

const void* Queue::back() const
{
	return tail ? tail->data : 0;
}

void Queue::push(void* d)
{
	if(!head)
		head = tail = new Node(d);
	else
		tail->next = new Node(d);
}

void Queue::pop()
{
	if(!head) return;
	Node *tmp = head;
	head = head->next;
	delete tmp;
}




