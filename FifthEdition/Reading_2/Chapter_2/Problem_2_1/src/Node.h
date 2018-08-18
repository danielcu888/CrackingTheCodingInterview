/*
 * Node.h
 *
 *  Created on: Mar 16, 2012
 *      Author: danielcumberbatch
 */

#ifndef NODE_H_
#define NODE_H_

#include <map>
#include <iostream>

using std::map; using std::cout;
using std::endl;

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

bool deleteDup(Node *head)
{
	map<int, bool> m;
	if(!head) return false;
	m[head->data] = true;

	while(head)
	{
		Node *tmp = head->next;
		if(!tmp) break;
		if(m[tmp->data])
		{
			Node *tmp2 = tmp->next;
			delete tmp;
			head->next = tmp2;
		}
		else
			m[tmp->data] = true;
		head = head->next;
	}
	return true;
}

bool deleteDup2(Node *head)
{
	if(!head) return false;
	Node *p1 = head;

	while(p1->next)
	{
		Node *p2 = p1;
		while(p2->next)
		{
			if(p2->next->data == p1->data)
			{
				Node *tmp = p2->next;
				p2->next = p2->next->next;
				delete tmp;
			}
			else
				p2 = p2->next;
		}
		p1 = p1->next;
	}
	return true;
}

#endif /* NODE_H_ */
