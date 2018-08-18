/*
 * Node.cpp
 *
 *  Created on: Apr 18, 2012
 *      Author: danielcumberbatch
 */

#include "Node.h"

bool createQueue(Node **head, Node **tail)
{
	*head = *tail = NULL;
	return true;
}

bool deleteQueue(Node **head, Node **tail)
{
	if(!*head) return false;
	while(*head)
	{
		Node *tmp = (*head)->next;
		if(*tail == *head)
			*tail = tmp;
		delete *head;
		*head = tmp;
	}
	return true;
}

bool push(Node **head, Node **tail, int d)
{
	Node *tmp = new Node;
	if(!tmp) return false;
	tmp->data = d;
	tmp->next = NULL;

	if(!*head)
	{
		*head = *tail = tmp;
		return true;
	}
	(*tail)->next = tmp;
	*tail = tmp;
	return true;
}

bool pop(Node **head, Node **tail)
{
	if(!*head)
		return false;
	Node *tmp = (*head)->next;
	if(*head == *tail) *tail = tmp;
	delete *head;
	*head = tmp;
	return true;
}

bool front(Node *head, Node *tail, int& d)
{
	if(!head) return false;
	d = head->data;
	return true;
}

bool back(Node *head, Node *tail, int& d)
{
	if(!tail) return false;
	d = tail->data;
	return true;
}

size_t size(Node *head, Node *tail)
{
	size_t sz = 0;
	while(head)
	{
		++sz;
		head = head->next;
	}
	return sz;
}

bool empty(Node *head, Node *tail)
{
	return head;
}


