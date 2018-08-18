/*
 * Node.cpp
 *
 *  Created on: Apr 16, 2012
 *      Author: danielcumberbatch
 */

#include "Node.h"
#include <stack>

using std::stack;

Node *summation(Node *n1, Node *n2)
{
	int num1 = 0, num2 = 0;
	int mult = 1;
	while(n1)
	{
		num1 += n1->data * mult;
		n1 = n1->next;
		mult *= 10;
	}
	mult = 1;
	while(n2)
	{
		num2 += n2->data * mult * 10;
		n2 = n2->next;
		mult *= 10;
	}
	int sum = num1 + num2;
	Node *ret = new Node(sum % 10);
	Node *tmp = ret;
	while((sum /= 10) > 0)
	{
		tmp->next = new Node(sum % 10);
		tmp = tmp->next;
	}
	return ret;
}

Node *reverseSummation(Node *n1, Node *n2)
{
	int num1 = 0, num2 = 0;
	while(n1)
	{
		num1 *= 10;
		num1 += n1->data;
		n1 = n1->next;
	}
	while(n2)
	{
		num2 *= 10;
		num2 += n2->data;
		n2 = n2->next;
	}
	int sum = num1 + num2;
	stack<int> s;
	while(sum > 0)
	{
		s.push(sum % 10);
		sum/=10;
	}
	Node *ret = new Node(s.top());
	s.pop();
	Node *tmp = ret;
	while(!s.empty())
	{
		tmp->next = new Node(s.top());
		s.pop();
		tmp = tmp->next;
	}
	return ret;
}
