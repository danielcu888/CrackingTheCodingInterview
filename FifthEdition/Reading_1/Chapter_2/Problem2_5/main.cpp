/*
 * main.cpp
 *
 *  Created on: Dec 22, 2011
 *      Author: danielcumberbatch
 */

#include "Problem2_5.h"
#include <iostream>

using std::cout; using std::endl;

int main(int argc, char** argv)
{
	LinkedListNode* head = new LinkedListNode(7);
	LinkedListNode::appendToTail(head, new LinkedListNode(1));
	LinkedListNode::appendToTail(head, new LinkedListNode(6));
	LinkedListNode::displayLL(head);

	LinkedListNode* head2 = new LinkedListNode(5);
	LinkedListNode::appendToTail(head2, new LinkedListNode(9));
	LinkedListNode::appendToTail(head2, new LinkedListNode(2));
	LinkedListNode::displayLL(head2);

	LinkedListNode::displayLL(LinkedListNode::sum(head, head2));

	LinkedListNode* head3 = new LinkedListNode(6);
	LinkedListNode::appendToTail(head3, new LinkedListNode(1));
	LinkedListNode::appendToTail(head3, new LinkedListNode(7));
	LinkedListNode::displayLL(head3);

	LinkedListNode* head4 = new LinkedListNode(2);
	LinkedListNode::appendToTail(head4, new LinkedListNode(9));
	LinkedListNode::appendToTail(head4, new LinkedListNode(5));
	LinkedListNode::displayLL(head4);

	LinkedListNode::displayLL(LinkedListNode::sumFor(head3, head4));

	return 0;
}
