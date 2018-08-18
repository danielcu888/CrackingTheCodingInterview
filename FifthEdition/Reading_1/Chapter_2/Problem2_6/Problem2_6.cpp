/*
 * Problem2_6.cpp
 *
 *  Created on: Dec 23, 2011
 *      Author: danielcumberbatch
 */

#include "Problem2_6.h"

LinkedListNode* LinkedListNode::appendToTail(LinkedListNode*& head, LinkedListNode* n)
{
	if(!head)
		head = n;
	else
	{
		LinkedListNode* tmp = head;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = n;
	}

	return head;
}

LinkedListNode* LinkedListNode::begCircLL(LinkedListNode* head)
{
	if(!head) return 0;
	LinkedListNode *p1 = head, *p2 = head, *p3 = head->next;
	int maxNum = 0;
	while(p3 && p2 != p3)
	{
		++maxNum;
		p3 = p3->next;
		if(p2 == p3) break;
		++maxNum;
		p3 = p3->next;
		if(p2 == p3) break;
		p2 = p2->next;
	}
	if(!p3) return 0;
	p3 = p3->next;

	while(true)
	{
		int p1Steps = 0;
		while(p1 != p2 && p1 != p3 && p1Steps < maxNum)
		{
			++p1Steps;
			p1 = p1->next;
		}

		if(p1 == p2)
		{
			p1 = head;
			p1Steps = 0;
			p2 = p2->next;
			p3 = p3->next;
		}
		else if(p1 == p3)
			return p3;
		else
			return 0; //no beginning to circular linked list
	}
	return 0;
}
