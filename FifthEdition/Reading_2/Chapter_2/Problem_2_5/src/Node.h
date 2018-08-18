/*
 * Node.h
 *
 *  Created on: Mar 16, 2012
 *      Author: danielcumberbatch
 */

#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <cmath>

using std::cout; using std::endl;
using std::pow;

struct Node
{
	Node(int data_ = 0, Node *next_ = 0)
		:	data(data_), next(next_)
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

Node *sum(Node *head1, Node *head2)
{
	if(!head1 && !head2) return new Node();

	int sum1 = 0, sum2 = 0, sum = 0;
	int count = 0;
	while(head1)
	{
		sum1 += head1->data * pow(10.0, count++);
		head1 = head1->next;
	}

	count = 0;

	while(head2)
	{
		sum2 += (head2->data)* pow(10.0, count++);
		head2 = head2->next;
	}

	sum = sum1 + sum2;

	Node *ret = 0, *tail = 0;
	while(sum > 0)
	{
		int tmp = sum % 10;
		sum /= 10;
		if(!ret)
			ret = tail = new Node(tmp);
		else
		{
			tail->next = new Node(tmp);
			tail = tail->next;
		}
	}
	return ret;
}


Node *sum2(Node *head1, Node *head2)
{
	if(!head1 && !head2) return new Node();

	int sum1 = 0, sum2 = 0, sum = 0;
	while(head1)
	{
		sum1 *= 10;
		sum1 += head1->data;
		head1 = head1->next;
	}

	while(head2)
	{
		sum2 *= 10;
		sum2 += head2->data;
		head2 = head2->next;
	}

	sum = sum1 + sum2;

	Node *ret = 0;
	while(sum > 0)
	{
		int tmp = sum % 10;
		sum /= 10;

		if(!ret)
			ret = new Node(tmp);
		else
		{
			Node *n = new Node(tmp, ret);
			ret = n;
		}
	}
	return ret;
}



#endif /* NODE_H_ */
