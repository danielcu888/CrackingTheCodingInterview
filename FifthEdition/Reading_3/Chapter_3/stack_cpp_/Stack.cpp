/*
 * Stack.cpp
 *
 *  Created on: Apr 18, 2012
 *      Author: danielcumberbatch
 */

#include "Stack.h"
#include <stdexcept>
#include <cstddef>

using std::logic_error; using std::size_t;

Stack::~Stack()
{
	while(head)
	{
		Node *tmp = head->next;
		delete head;
		head = tmp;
	}
}

int Stack::top() const
{
	if(!head)
		throw logic_error("Stack is empty!");
	return head->data;
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

void Stack::push(int d)
{
	Node *n = new Node(d, head);
	head = n;
}

void Stack::pop()
{
	if(!head)
		throw logic_error("Stack is empty!");
	Node *tmp = head->next;
	delete head;
	head = tmp;
}

bool Stack::empty() const
{
	return head;
}
