/*
 * Node.h
 *
 *  Created on: Apr 18, 2012
 *      Author: danielcumberbatch
 */

#ifndef NODE_H_
#define NODE_H_

#include <stddef.h>

typedef struct Node {
	int data = 0;
	struct Node *next = NULL;
} Node;

bool createStack(Node **head);
bool deleteStack(Node **head);
bool top(Node *head, int& n);
bool push(Node **head, int n);
bool pop(Node **head);
size_t size(Node *head);
bool empty(Node *head);

#endif /* NODE_H_ */
