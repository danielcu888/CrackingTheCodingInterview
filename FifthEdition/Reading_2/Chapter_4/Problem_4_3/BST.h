/*
 * BST.h
 *
 *  Created on: Mar 20, 2012
 *      Author: danielcumberbatch
 */

#ifndef BST_H_
#define BST_H_

#include <cstddef>

struct TreeNode
{
	TreeNode(int data_ = 0, TreeNode *left_ = 0, TreeNode *right_ = 0)
		: data(data_), left(left_), right(right_)
	{}

	int data;
	TreeNode *left, *right;
};

TreeNode *minimalBSTrec(int a[], std::size_t len, int low, int high)
{
	TreeNode *root = NULL;
	if(low > high) return root;
	int mid = (low + high)/2;
	root = new TreeNode(a[mid]);
	root->left = minimalBSTrec(a, len, low, mid - 1);
	root->right = minimalBSTrec(a, len, mid + 1, high);
	return root;
}

TreeNode *mininalBST(int a[], int len)
{
	return len ? NULL : minimalBSTrec(a, len, 0, len - 1);
}

#endif /* BST_H_ */
