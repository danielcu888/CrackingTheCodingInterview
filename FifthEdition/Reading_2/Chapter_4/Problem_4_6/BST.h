/*
 * BST.h
 *
 *  Created on: Mar 21, 2012
 *      Author: danielcumberbatch
 */

#ifndef BST_H_
#define BST_H_

#include <cstddef>

struct TreeNode
{
	TreeNode(int data_ = 0, TreeNode *left_ = 0, TreeNode *right_ = 0, TreeNode *parent_ = 0)
		: data(data_), left(left_), right(right_), parent(parent_)
	{}

	int data;
	TreeNode *left, *right, *parent;
};

TreeNode *inOrderSucc(TreeNode *target)
{
	if(target->right)
	{
		TreeNode *tmp = target->right;
		while(tmp->left)
			tmp = tmp->left;
		return tmp;
	}
	else
	{
		TreeNode *tmp = target;
		while(tmp->parent && tmp->parent->data < tmp->data)
			tmp = tmp->parent;
		if(!tmp->parent)
			return NULL;
		else
			return tmp->parent;
	}
}

#endif /* BST_H_ */
