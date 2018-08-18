/*
 * Node.h
 *
 *  Created on: Mar 16, 2012
 *      Author: danielcumberbatch
 */

#ifndef NODE_H_
#define NODE_H_

struct Node
{
	Node(int data_ = 0, Node *next_ = 0)
		:	data(data_), next(next_)
	{}

	int data;
	Node *next;
};

bool appendToTail(Node **head, int d)
{
	Node *n = new Node(d);
	if(!n) return false;

	if(!*head)
	{
		*head = n;
		return true;
	}

	Node *tmp = *head;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = n;
	return true;
}

bool deleteNode(Node **head, int d)
{
	if(!*head) return false;

	if((*head)->data == d)
	{
		Node *tmp = (*head)->next;
		delete *head;
		*head = tmp;
		return true;
	}

	Node *tmp = *head;
	while(tmp->next->data != d)
		tmp = tmp->next;
	if(!tmp->next)
		return false;
	Node *tmp2 = tmp->next->next;
	delete tmp->next;
	tmp->next = tmp2;
	return true;
}

#endif /* NODE_H_ */
