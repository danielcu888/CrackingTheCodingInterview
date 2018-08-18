/*
 * Node.h
 *
 *  Created on: Apr 16, 2012
 *      Author: danielcumberbatch
 */

#ifndef NODE_H_
#define NODE_H_

#include <stddef.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

Node *findKthToLast(Node *head, size_t k);

#endif /* NODE_H_ */
