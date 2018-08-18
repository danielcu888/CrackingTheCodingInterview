/*
 * Node.h
 *
 *  Created on: Mar 16, 2012
 *      Author: danielcumberbatch
 */

#ifndef NODE_H_
#define NODE_H_

#include <cstddef>

struct Node
{
	Node(int data_ = 0, Node *next_ = 0)
		: data(data_), next(next_)
	{}

	int data;
	Node *next;
};

Node *findkthToLast(Node *head, std::size_t k)
{
	Node *p1 = head, *p2 = head;
	size_t count = 0;
	while(count++ < k && p2)
		p2 = p2->next;
	if(!p2) return NULL;

	while(p2->next)
	{
		p1 = p1->next;
		p2 = p2->next;
	}

	return p1;
}


#endif /* NODE_H_ */
