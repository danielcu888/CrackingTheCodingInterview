/*
 * Problem2_2.cpp
 *
 *  Created on: Dec 20, 2011
 *      Author: danielcumberbatch
 */

#include "Problem2_2.hpp"
#include <cstddef>

static LinkedListNode* LinkedListNode::kthToLast(LinkedListNode* head, int k)
{
	if(!head) return NULL;
	LinkedListNode *tmp1 = head;
	int count = 0;
	tmp1 = head;
	while(count < k)
	{
		tmp1 = tmp1->next;
		if(!tmp1) return NULL;
		++count;
	}
	LinkedListNode *tmp2 = head;
	while(tmp1)
	{
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	return tmp1;
}
