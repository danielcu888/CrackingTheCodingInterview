/*
 * Problem2_5.cpp
 *
 *  Created on: Dec 21, 2011
 *      Author: danielcumberbatch
 */

#include "Problem2_5.h"
#include <cstddef>
#include <cmath>
#include <iostream>

using std::cout; using std::endl;
using std::pow;

LinkedListNode* LinkedListNode::sum(LinkedListNode* n1, LinkedListNode* n2)
{
	int tot = LinkedListNode::readNum(n1) + LinkedListNode::readNum(n2);
	return LinkedListNode::writeNum(tot);
}

LinkedListNode* LinkedListNode::sumFor(LinkedListNode* n1, LinkedListNode* n2)
{
	int tot = LinkedListNode::readNumFor(n1) + LinkedListNode::readNumFor(n2);
	return LinkedListNode::writeNumFor(tot);
}

int LinkedListNode::readNum(LinkedListNode* head)
{
	int ret = 0;
	int count = 0;
	while(head)
	{
		ret += head->data * static_cast<int>(pow(10.0, static_cast<double>(count++)));
		head = head->next;
	}
	return ret;
}

int LinkedListNode::readNumFor(LinkedListNode* head)
{
	int ret = 0;
	while(head)
	{
		ret *= 10;
		ret += head->data;
		head = head->next;
	}
	return ret;
}

void LinkedListNode::appendToTail(LinkedListNode*& head, LinkedListNode* n)
{
	if(!head)
	{
		head = n;
		return;
	}

	LinkedListNode* tmp = head;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = n;
}

LinkedListNode* LinkedListNode::writeNum(int n)
{
	LinkedListNode* head = 0;
	while(n > 0)
	{
		LinkedListNode::appendToTail(head, new LinkedListNode(n % 10));
		n -= n % 10;
		n /= 10;
	}
	return head;
}

void LinkedListNode::appendToHead(LinkedListNode*& head, LinkedListNode* n)
{
	if(!head)
	{
		head = n;
		return;
	}
	n->next = head;
	head = n;
}

LinkedListNode* LinkedListNode::writeNumFor(int n)
{
	LinkedListNode* head = 0;
	while(n > 0)
	{
		LinkedListNode::appendToHead(head, new LinkedListNode(n % 10));
		n -= n % 10;
		n /= 10;
	}
	return head;
}

void LinkedListNode::displayLL(LinkedListNode* head)
{
	if(!head) return;
	while(head)
	{
		cout << head->data;
		head = head->next;
	}
	cout << endl;
}
