/*
 * Problem2_5.h
 *
 *  Created on: Dec 21, 2011
 *      Author: danielcumberbatch
 */

#ifndef PROBLEM2_5_H_
#define PROBLEM2_5_H_

#include <cstddef>

struct LinkedListNode
{
	LinkedListNode(int d)
		: data(d), next(NULL)
	{}

	int data;
	LinkedListNode* next;

	static LinkedListNode* sum(LinkedListNode*, LinkedListNode*);
	static LinkedListNode* sumFor(LinkedListNode*, LinkedListNode*);

	static int readNum(LinkedListNode*);
	static int readNumFor(LinkedListNode*);

	static LinkedListNode* writeNum(int);
	static LinkedListNode* writeNumFor(int);

	static void appendToTail(LinkedListNode*&, LinkedListNode*);
	static void appendToHead(LinkedListNode*&, LinkedListNode*);

	static void displayLL(LinkedListNode*);
};

#endif /* PROBLEM2_5_H_ */
