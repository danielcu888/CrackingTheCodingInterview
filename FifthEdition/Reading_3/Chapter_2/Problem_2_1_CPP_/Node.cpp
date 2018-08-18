/*
 * Node.cpp
 *
 *  Created on: Apr 16, 2012
 *      Author: danielcumberbatch
 */

#include "Node.h"
#include <map>

using std::map;

//Runtime O(NlogN), Memory O(N)
bool Node::removeDuplicates(Node *head)
{
	if(!head) return false;
	map<int, bool> m;
	m[head->data] = true;

	if(!head->next) return false;

	while(head->next)
	{
		if(m[head->next->data])
		{
			Node *tmp = head->next;
			head->next = tmp->next;
			delete tmp;
		}
		else
		{
			m[head->next->data] = true;
			head = head->next;
		}
	}
	return true;
}

//O(N^2) runtime, O(1) memory
bool Node::removeDuplicatesWithoutBuffer(Node *head)
{
	if(!head) return false;
	if(!head->next) return false;

	while(head->next)
	{
		int d = head->data;
		Node *tmp = head;
		while(tmp->next)
		{
			if(tmp->next->data == d)
			{
				Node *tmp2 = tmp->next;
				tmp->next = tmp2->next;
				delete tmp2;
			}
			else
				tmp = tmp->next;
		}
		head = head->next;
	}
	return true;
}

