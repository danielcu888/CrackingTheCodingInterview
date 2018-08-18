/*
 * BST.h
 *
 *  Created on: Mar 20, 2012
 *      Author: danielcumberbatch
 */

#ifndef BST_H_
#define BST_H_

#include <cstddef>
#include <queue>
#include <cmath>

struct TreeNode
{
	TreeNode(int data_ = 0, TreeNode *left_ = 0, TreeNode *right_ = 0)
		: data(data_), left(left_), right(right_), next(0)
	{}

	int data;
	TreeNode *left, *right, *next;
};

TreeNode *minimalBST(int a[], std::size_t len, int low, int high)
{
	TreeNode *root = NULL;
	if(low > high) return root;
	int mid = (low + high)/2;
	root = new TreeNode(a[mid]);
 	root->right = minimalBST(a, len, mid + 1, high);
	return root;
}

void getHeightRec(TreeNode *root, std::size_t& max_level, std::size_t level)
{
	if(!root) return;
	if(!root->left && !root->right)
	{
		max_level = std::max(level, max_level);
		return;
	}
	if(root->left) getHeightRec(root->left, max_level, level+1);
	if(root->right) getHeightRec(root->right, max_level, level+1);
}

std::size_t getHeight(TreeNode *root)
{
	std::size_t max_level = 0;
	getHeightRec(root, max_level, 0);
	return max_level;
}

void appendToTail(TreeNode*& head, TreeNode *root)
{
	if(!head)
		head = root;
	else
	{
		TreeNode *tmp = head;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = root;
	}
}

void genLLrec(TreeNode *root, std::vector<TreeNode*>& v, std::size_t level)
{
	if(!root) return;
	appendToTail(v[level], root);
	if(root->left) genLLrec(root->left, v, level + 1);
	if(root->right) genLLrec(root->right, v, level + 1);
}

std::vector<TreeNode*> genLL(TreeNode *root)
{
	std::size_t height = getHeight(root);
	std::vector<TreeNode*> v(height, NULL);
	genLLrec(root, v, 0);
	return v;
}

#endif /* BST_H_ */
