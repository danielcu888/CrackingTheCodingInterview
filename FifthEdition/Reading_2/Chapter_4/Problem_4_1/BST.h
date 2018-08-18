/*
 * BST.h
 *
 *  Created on: Mar 20, 2012
 *      Author: danielcumberbatch
 */

#ifndef BST_H_
#define BST_H_

#include <cstddef>
#include <cmath>

struct Node
{
	Node(int data_ = 0, Node *left_ = 0, Node *right_ = 0)
		: data(data_), left(left_), right(right_)
	{}

	int data;
	Node *left, *right;
};

Node *createBST(int a[], std::size_t len, int low, int high)
{
	Node *root = NULL;
	if(low > high) return root;
	int mid = (low + high)/2;
	root = new Node(a[mid]);
	root->left = createBST(a, len, low, mid - 1);
	root->right = createBST(a, len, mid + 1, high);
	return root;
}

int checkHeight(Node *root)
{
	if(!root) return 0;
	int leftHeight = checkHeight(root->left);
	if(leftHeight == -1) return -1;
	int rightHeight = checkHeight(root->right);
	if(rightHeight == -1) return -1;

	if(std::abs(leftHeight - rightHeight) > 1)
		return -1;
	else
		return std::max(leftHeight, rightHeight) + 1;
}

bool isBalanced(Node *root)
{
	return checkHeight(root) == -1;
}

int getHeight(Node *root)
{
	if(!root) return 0;
	return std::max(getHeight(root->left), getHeight(root->right)) + 1;
}

bool isBalanced2(Node *root)
{
	if(!root) return false;
	int heightDiff = std::abs(getHeight(root->left) - getHeight(root->right));
	if(heightDiff > 1) return false;
	return isBalanced2(root->left) && isBalanced2(root->right);
}


#endif /* BST_H_ */
