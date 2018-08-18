/*
 * Node.h
 *
 *  Created on: Apr 16, 2012
 *      Author: danielcumberbatch
 */

#ifndef NODE_H_
#define NODE_H_

typedef struct Node {
	int data;
	struct Node *next;
} Node;

enum BOOL {FALSE = 0, TRUE = 1};

enum BOOL partition(Node **head, int x);

#endif /* NODE_H_ */
