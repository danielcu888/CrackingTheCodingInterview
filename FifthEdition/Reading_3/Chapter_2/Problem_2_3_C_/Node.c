/*
 * Node.c
 *
 *  Created on: Apr 16, 2012
 *      Author: danielcumberbatch
 */

#include "Node.h"

enum BOOL deleteMiddleNode(Node *middleNode)
{
	if(!middleNode) return FALSE;
	if(!middleNode->next) return FALSE;
	middleNode->data = middleNode->next->data;
	Node *tmp = middleNode->next;
	middleNode->next = tmp->next;
	free(tmp);
	return TRUE;
}
