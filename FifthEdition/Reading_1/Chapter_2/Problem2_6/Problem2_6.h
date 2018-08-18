/*
 * Problem2_6.h
 *
 *  Created on: Dec 23, 2011
 *      Author: danielcumberbatch
 */

#ifndef PROBLEM2_6_H_
#define PROBLEM2_6_H_

class LinkedListNode
{
public:
	LinkedListNode(int d)
	: data(d), next(0)
	{}

	int data;
	LinkedListNode* next;

	static LinkedListNode* appendToTail(LinkedListNode*&, LinkedListNode*);
	static LinkedListNode* begCircLL(LinkedListNode*);
};

#endif /* PROBLEM2_6_H_ */
