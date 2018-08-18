/*
 * Stack.cpp
 *
 *  Created on: Dec 29, 2011
 *      Author: danielcumberbatch
 */

#include "Stack.hpp"
#include <cstddef>

using std::size_t;

Stack::~Stack()
{
	while(head)
	{
		Node *tmp = head->next;
		delete head;
		head = tmp;
	}
}

bool Stack::empty() const
{
	return head;
}

size_t Stack::size() const
{
	int ret = 0;
	Node *tmp = head;
	while(tmp)
	{
		++ret;
		tmp = tmp->next;
	}
	return ret;
}

const void* Stack::top() const
{
	return head ? head->data : 0;
}

void Stack::push(void* data)
{
	if(!head)
		head = new Node(data);
	else
	{
		Node *tmp = new Node(data);
		tmp->next = head;
		head = tmp;
	}
}

void Stack::pop()
{
	if(!head)
		return;
	else
	{
		Node *tmp = head;
		head = head->next;
		delete tmp;
	}
}
