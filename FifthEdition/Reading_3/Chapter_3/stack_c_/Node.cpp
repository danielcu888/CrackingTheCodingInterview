/*
 * Node.cpp
 *
 *  Created on: Apr 18, 2012
 *      Author: danielcumberbatch
 */

#include "Node.h"
#include <stddef.h>

bool createStack(Node **head)
{
	*head = NULL;
	return true;
}

bool deleteStack(Node **head)
{
	if(!*head) return false;
	while(*head)
	{
		Node *tmp = *head;
		*head = (*head)->next;
		delete tmp;
	}
	return true;
}

bool top(Node *head, int& n)
{
	if(!head) return false;
	n = head->data;
	return true;
}

bool push(Node **head, int n)
{
	Node *tmp = new Node();
	if(!tmp) return false;
	tmp->data = n;
	tmp->next = *head;
	*head = tmp;
	return true;
}

bool pop(Node **head)
{
	if(!*head) return false;
	Node *tmp = *head;
	*head = (*head)->next;
	delete tmp;
	return true;
}

size_t size(Node *head)
{
	size_t n = 0;
	while(head)
	{
		++n;
		head = head->next;
	}
	return n;
}

bool empty(Node *head)
{
	return head;
}
