/*
 * Stack.cpp
 *
 *  Created on: Apr 18, 2012
 *      Author: danielcumberbatch
 */

#include "Stack.h"
#include <stdexcept>

using std::logic_error; using std::size_t;

Stack::~Stack()
{
	if(!head)
		throw logic_error("Empty Stack!");
	while(head)
	{
		Node *tmp = head->next;
		delete head;
		head = tmp;
	}
	while(min_head)
	{
		Node *tmp = min_head->next;
		delete min_head;
		min_head = tmp;
	}
}

void Stack::push(int d)
{
	Node *tmp = new Node(d, NULL);
	Node *tmp2 = new Node(d, NULL);
	if(!head)
	{
		head = tmp;
		min_head = tmp2;
	}
	else
	{
		tmp->next = head;
		head = tmp;
		if(d <= min())
		{
			tmp2->next = min_head;
			min_head = tmp2;
		}
	}
}

void Stack::pop()
{
	if(!head)
		throw logic_error("Empty Stack!");
	Node *tmp = head->next;
	int data = head->data;
	delete head;
	head = tmp;
	if(data == min())
	{
		Node *tmp2 = min_head->next;
		delete min_head;
		min_head = tmp2;
	}
}

size_t Stack::size() const
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

bool Stack::empty() const
{
	return head;
}

int Stack::top() const
{
	if(!head)
		throw logic_error("Empty Stack!");
	return head->data;
}

int Stack::min() const
{
	if(!min_head)
		throw logic_error("Empty Stack!");
	return min_head->data;
}




