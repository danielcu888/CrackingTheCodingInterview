/*
 * BST.h
 *
 *  Created on: Mar 20, 2012
 *      Author: danielcumberbatch
 */

#ifndef BST_H_
#define BST_H_

#include <iostream>
#include <queue>

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
	Node *ret = NULL;
	if(low > high) return ret;
	int mid = (low + high)/2;
	ret = new Node(a[mid]);
	ret->left = createBST(a, len, low, mid-1);
	ret->right = createBST(a, len, mid+1, high);
	return ret;
}

void preOrder(Node *root, int level)
{
	if(!root) return;
	std::cout << "data = " << root->data << ", level = " << level << std::endl;
	if(root->left) preOrder(root->left, level+1);
	if(root->right) preOrder(root->right, level+1);
}

void inOrder(Node *root, int level)
{
	if(!root) return;
	if(root->left) inOrder(root->left, level + 1);
	std::cout << "data = " << root->data << ", level = " << level << std::endl;
	if(root->right) inOrder(root->right, level + 1);
}

void postOrder(Node *root, int level)
{
	if(!root) return;
	if(root->right) postOrder(root->right, level+1);
	std::cout << "data = " << root->data << ", level = " << level << std::endl;
	if(root->left) postOrder(root->left, level+1);
}

Node *depthFirstSearch(Node *root, int val)
{
	if(!root) return NULL;
	if(root->data == val) return root;
	else if(root->data > val) return depthFirstSearch(root->left, val);
	else return depthFirstSearch(root->right, val);
}

Node *breadthFirstSearch(Node *root, int val)
{
	if(!root) return NULL;
	std::queue<Node*> s;
	s.push(root);
	while(!s.empty())
	{
		Node *tmp = s.front();
		s.pop();
		if(tmp->data == val) return tmp;
		if(tmp->left) s.push(root->left);
		if(tmp->right) s.push(tmp->right);
	}
	return NULL;
}

#endif /* BST_H_ */







