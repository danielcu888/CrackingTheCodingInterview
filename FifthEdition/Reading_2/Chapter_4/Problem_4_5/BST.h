/*
 * BST.h
 *
 *  Created on: Mar 20, 2012
 *      Author: danielcumberbatch
 */

#ifndef BST_H_
#define BST_H_

#include <cstddef>
#include <iostream>

struct TreeNode
{
	TreeNode(int data_ = 0, TreeNode *left_ = 0, TreeNode *right_ = 0)
		: data(data_), left(left_), right(right)
	{}

	int data;
	TreeNode *left, *right;
};

TreeNode *minimalBST(int a[], std::size_t len, int low, int high)
{
	TreeNode *ret = NULL;
	if(low > high) return ret;
	int mid = (low + high)/2;
	ret = new TreeNode(a[mid]);
	ret->left = minimalBST(a, len, low, mid - 1);
	ret->right = minimalBST(a, len, mid + 1, high);
	return ret;
}

bool isBST(TreeNode *root)
{
	if(!root) return false;
	bool flagLeft = true, flagRight = true;
	if(root->left)
		flagLeft = (root->left->data <= root->data) ? isBST(root->left) : false;
	if(root->right)
		flagRight = (root->right->data >= root->data) ? isBST(root->right) : false;
	return flagLeft && flagRight;
}

#endif /* BST_H_ */
