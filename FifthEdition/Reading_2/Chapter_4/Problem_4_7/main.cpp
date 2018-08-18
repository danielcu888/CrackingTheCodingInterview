/*
 * main.cpp
 *
 *  Created on: Mar 21, 2012
 *      Author: danielcumberbatch
 */

#include "TreeNode.h"
#include <cstddef>
#include <iostream>

using std::size_t; using std::cout; using std::endl;

int main()
{
	int a[] = {1,3,5,7,9,11,15};
	size_t len = sizeof(a)/sizeof(*a);
	TreeNode *root = minimalBT(a, len, 0, len - 1);
	TreeNode *tmp = FCA(root, root->left->left, root->left);
	if(!tmp) cout << "null" << endl;
	else cout << tmp->data << endl;
	return 0;
}


