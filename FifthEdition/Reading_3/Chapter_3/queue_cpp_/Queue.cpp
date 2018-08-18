/*
 * Queue.cpp
 *
 *  Created on: Apr 18, 2012
 *      Author: danielcumberbatch
 */

#include "Queue.h"
#include <cstddef>
#include <stdexcept>

using std::logic_error;
using std::size_t;

Queue::~Queue()
{
	while(head)
	{
		Node *tmp = head->next;
		delete head;
		head = tmp;
	}
	tail = NULL;
}

void Queue::push(int d)
{
	Node *tmp = new Node(d, NULL);
	if(!head)
		head = tail = tmp;
	else
	{
		tail->next = tmp;
		tail = tmp;
	}
}

void Queue::pop()
{
	if(!head)
		throw logic_error("Empty Stack!");
	Node *tmp = head->next;
	if(tail == head)
		tail = tmp;
	delete head;
	head = tmp;
}

int Queue::front() const
{
	if(!head)
		throw logic_error("Empty Stack!");
	return head->data;
}

int Queue::back() const
{
	if(!head)
		throw logic_error("Empty Stack!");
	return tail->data;
}

size_t Queue::size() const
{
	size_t sz = 0;
	Node *tmp = head;
	while(tmp)
	{
		++sz;
		tmp = tmp->next;
	}
	return sz;
}

bool Queue::empty() const
{
	return head;
}



