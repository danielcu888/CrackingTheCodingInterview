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
	Node *next = NULL;
} Node;

bool createQueue(Node **head, Node **tail);
bool deleteQueue(Node **head, Node **tail);

bool push(Node **head, Node **tail, int d);
bool pop(Node **head, Node **tail);

bool front(Node *head, Node *tail, int& d);
bool back(Node *head, Node *tail, int& d);
size_t size(Node *head, Node *tail);
bool empty(Node *head, Node *tail);

#endif /* NODE_H_ */
