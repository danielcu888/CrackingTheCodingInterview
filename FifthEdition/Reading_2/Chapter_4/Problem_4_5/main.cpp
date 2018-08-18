/*
 * main.cpp
 *
 *  Created on: Mar 20, 2012
 *      Author: danielcumberbatch
 */

#include "BST.h"
#include <cstddef>
#include <iostream>

using std::size_t; using std::cout;
using std::endl;

int main()
{
	int a[] = {1,4,5,8,9,10};
	size_t len = sizeof(a)/sizeof(*a);
	TreeNode *root = minimalBST(a, len, 0, len - 1);
	bool result = isBST(root);
	cout << result << endl;
	return 0;
}


