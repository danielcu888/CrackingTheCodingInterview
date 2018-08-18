/*
 * Problem2_1.h
 *
 *  Created on: Dec 20, 2011
 *      Author: danielcumberbatch
 */

#ifndef PROBLEM2_1_H_
#define PROBLEM2_1_H_

#include <cstddef>

struct Node
{
public:
	Node(int d)
	: next(NULL), val(d)
	{}

	static void appendToTail(Node*&, int);
	static void deleteNode(Node*&, int);

	static void removeDuplicates(Node*);
	static void removeDuplicates2(Node*);

	Node* next;
	int val;
};

#endif /* PROBLEM2_1_H_ */
