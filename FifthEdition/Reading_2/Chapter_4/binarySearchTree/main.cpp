/*
 * main.cpp
 *
 *  Created on: Mar 20, 2012
 *      Author: danielcumberbatch
 */

#ifndef MAIN_CPP_
#define MAIN_CPP_

#include "BST.h"
#include <cstddef>
#include <iostream>

using std::cout; using std::endl;

int main()
{
	int a[] = {0,1,4,5,7,9,11};
	size_t len = sizeof(a)/sizeof(*a);
	Node *root = createBST(a, len, 0, len-1);
	postOrder(root, 0);

	Node *found = depthFirstSearch(root, 9);
	cout << found->data << endl;

	Node *bfsfound = breadthFirstSearch(root, 9);
	cout << bfsfound->data << endl;

	return 0;
}

#endif /* MAIN_CPP_ */
