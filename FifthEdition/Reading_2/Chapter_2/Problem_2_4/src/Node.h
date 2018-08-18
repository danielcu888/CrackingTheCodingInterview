/*
 * Node.h
 *
 *  Created on: Mar 16, 2012
 *      Author: danielcumberbatch
 */

#ifndef NODE_H_
#define NODE_H_

#include <iostream>

using std::cout; using std::endl;

struct Node
{
	Node(int data_ = 0, Node *next_ = 0)
		: data(data_), next(next_)
	{}

	int data;
	Node *next;
};

void display(Node *head)
{
	while(head)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

bool xpartition(Node **head, int x)
{
	if((*head)->data >= x)
	{
		Node *tmp = *head;
		while(tmp->next && tmp->next->data >= x)
			tmp = tmp->next;
		if(!tmp->next) return false;
		Node *tmp2 = tmp->next;
		tmp->next = tmp->next->next;
		tmp2->next = *head;
		*head = tmp2;
	}

	Node *tmp = *head;
	while(tmp->next && tmp->next->data < x)
		tmp = tmp->next;
	if(!tmp->next) return false;

	Node *tmp2 = tmp;
	while(tmp2->next)
	{
		if(tmp2->next->data < x)
		{
			Node *tmp3 = tmp2->next;
			tmp2->next = tmp2->next->next;
			tmp3->next = tmp->next;
			tmp->next = tmp3;
			tmp = tmp3;
		}
		else
			tmp2 = tmp2->next;
	}
	return true;
}

#endif /* NODE_H_ */
