/*
 * Problem2_1.cpp
 *
 *  Created on: Dec 20, 2011
 *      Author: danielcumberbatch
 */

#include "Problem2_1.h"
#include <map>

using std::map;

void Node::appendToTail(Node*& head, int d)
{
	if(!head)
	{
		head = new Node(d);
		return;
	}

	Node* tmp = head;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = new Node(d);
	return;
}

void Node::deleteNode(Node*& head, int d)
{
	if(!head) return;
	if(head->val == d)
	{
		delete head;
		return;
	}

	Node* tmp = head;
	while(tmp->next && tmp->next->val != d)
		tmp = tmp->next;
	if(!tmp->next) return;
	Node *tmp2 = tmp->next;
	tmp->next = tmp2->next;
	delete tmp2;
}

//O(n^2)
void Node::removeDuplicates(Node* head)
{
	if(!head || !head->next) return;
	Node *tmp1 = head;
	while(tmp1->next)
	{
		Node *tmp2 = tmp1;
		while(tmp2->next && tmp2->next->val != tmp1->val)
			tmp2 = tmp2->next;
		if(!tmp2->next) continue;
		Node *tmp3 = tmp2->next;
		tmp2->next = tmp3->next;
		delete tmp3;
		tmp1 = tmp1->next;
	}
}

void Node::removeDuplicates2(Node* head)
{
	if(!head || !head->next) return;
	map<int, bool> nodes;
	nodes[head->val] = true;
	while(head->next)
	{
		if(nodes[head->next->val])
		{
			Node *tmp = head->next;
			head->next = tmp->next;
			delete tmp;
		}
		else
		{
			nodes[head->next->val] = true;
			head = head->next;
		}
	}
}














