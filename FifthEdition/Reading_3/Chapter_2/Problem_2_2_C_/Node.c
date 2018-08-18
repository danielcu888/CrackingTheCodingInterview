/*
 * Node.c
 *
 *  Created on: Apr 16, 2012
 *      Author: danielcumberbatch
 */

#include "Node.h"

Node *findKthToLast(Node *head, size_t k)
{
	if(!head) return NULL;
	Node *p1 = head, *p2 = head;
	size_t i;
	for(i = 0; i != k; ++k)
	{
		p1 = p1->next;
		if(!p1) return NULL;
	}
	while(p1->next)
	{
		p1 = p1->next;
		p2 = p2->next;
	}

	return p2;
}

