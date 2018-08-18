/*
 * TreeNode.h
 *
 *  Created on: Mar 21, 2012
 *      Author: danielcumberbatch
 */

#ifndef TREENODE_H_
#define TREENODE_H_

#include <cstddef>
#include <iostream>

struct TreeNode
{
	TreeNode(int data_ = 0, TreeNode *left_ = 0, TreeNode *right_ = 0)
		: data(data_), left(left_), right(right_)
	{}

	int data;
	TreeNode *left, *right;
};

TreeNode *minimalBT(int a[], std::size_t len, int low, int high)
{
	TreeNode *root = NULL;
	if(low > high) return root;
	int mid = (low + high)/2;
	root = new TreeNode(a[mid]);
	root->left = minimalBT(a, len, low, mid - 1);
	root->right = minimalBT(a, len, mid + 1, high);
	return root;
}

bool isChild(TreeNode *root, TreeNode *n)
{
	if(!root) return false;
	if(root == n) return true;
	return (isChild(root->left, n) || isChild(root->right, n));
}

TreeNode *FCA(TreeNode *root, TreeNode *n1, TreeNode *n2)
{
	std::cout << root->data << std::endl;
	if(!root) return NULL;
	if(root == n1 || root == n2) return root;
	if(!root->left && !root->right) return NULL;
	if(root->left && !root->right) return FCA(root->left, n1, n2);
	if(!root->left && root->right) return FCA(root->right, n1, n2);
	if(root->left && root->right)
	{
		if(isChild(root->left, n1) && isChild(root->right, n2))
			return root;
		if(isChild(root->left, n1) && isChild(root->left, n2))
			return FCA(root->left, n1, n2);
		if(isChild(root->right, n1) && isChild(root->right, n2))
			return FCA(root->right, n1, n2);
	}
	return NULL;
}

#endif /* TREENODE_H_ */
