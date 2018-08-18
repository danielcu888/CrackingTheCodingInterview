/*
 * Problem2_2.hpp
 *
 *  Created on: Dec 20, 2011
 *      Author: danielcumberbatch
 */

#ifndef PROBLEM2_2_HPP_
#define PROBLEM2_2_HPP_

struct LinkedListNode
{
	LinkedListNode(int d)
		: data(d)
	{}

	static LinkedListNode* kthToLast(LinkedListNode*, int);

	int data;
	LinkedListNode *next;
};




#endif /* PROBLEM2_2_HPP_ */
