/*
 * Node.h
 *
 *  Created on: Apr 16, 2012
 *      Author: danielcumberbatch
 */

#ifndef NODE_H_
#define NODE_H_

struct Node
{
	Node(int _data = 0, Node *_next = 0)
		: data(_data), next(_next)
	{}

	static bool removeDuplicates(Node*);
	static bool removeDuplicatesWithoutBuffer(Node*);

	int data;
	Node *next;
};

#endif /* NODE_H_ */
