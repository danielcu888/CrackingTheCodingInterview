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
	explicit Node(int data_ = 0, Node *next_ = 0)
		: data(data_), next(next_)
	{}

	int data;
	Node *next;
};

bool removeMiddleNodeTwo(Node *head)
{
	if(!head || !head->next) return false;
	Node *p1 = head, *p2 = head;

	while(p2 && p2->next)
	{
		p2 = p2->next;
		p2 = p2->next;
		if(p2 && p2->next)
			p1 = p1->next;
		else
		{
			Node *tmp = p1->next;
			p1->next = p1->next->next;
			delete tmp;
			return true;
		}
	}
	return false;
}

void removeMiddleNode(Node *c)
{
	c->data = c->next->data;
	Node *tmp = c->next;
	c->next = c->next->next;
	delete tmp;
}

#endif /* NODE_H_ */
