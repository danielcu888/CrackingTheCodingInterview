/*
 * Graph.h
 *
 *  Created on: Mar 20, 2012
 *      Author: danielcumberbatch
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <cstddef>
#include <queue>

enum STATE {VISITED = 0, VISITING = 1, UNVISITED = 2};

struct GraphNode
{
	GraphNode(int data_ = 0)
		: data(data_), state(UNVISITED)
	{}

	std::vector<GraphNode*> getAdjacent() const;

	int data;
	STATE state;
};

bool isPath(GraphNode*& gn1, GraphNode*& gn2)
{
	if(gn1 == gn2) return true;
	gn1->state == VISITED;
	std::vector<GraphNode*> adj = gn1->getAdjacent();
	for(std::size_t i = 0; i != adj.size(); ++i)
		if(adj[i]->state == UNVISITED)
			adj[i]->state == VISITING;
	for(std::size_t i = 0; i != adj.size(); ++i)
		if(adj[i]->state == VISITING && isPath(adj[i], gn2))
			return true;
	return false;
}

struct TreeNode
{
	TreeNode(int data_ = 0, TreeNode *left_ = 0, TreeNode *right_ = 0)
		:	data(data_), left(left), right(right_)
	{}

	int data;
	TreeNode *left, *right;
};

TreeNode *constructBST(int a[], int len, int low, int high)
{
	TreeNode *root = NULL;
	if(low > high) return root;
	int mid = (low + high)/2;
	root = new TreeNode(a[mid], NULL, NULL);
	root->left = constructBST(a, len, low, mid - 1);
	root->right = constructBST(a, len, mid + 1, high);
}

TreeNode *BFS(TreeNode *root, int val)
{
	if(!root) return NULL;
	std::queue<TreeNode*> q;
	q.push(root);
	while(!q.empty())
	{
		TreeNode *tmp = q.front();
		q.pop();
		if(tmp->data == val) return tmp;
		if(tmp->left) q.push(tmp->left);
		if(tmp->right) q.push(tmp->right);
	}
	return NULL;
}

class Graph;

bool isPathBFS(Graph& g, GraphNode*& start, GraphNode*& end)
{
	std::queue<GraphNode*> q;
	start->state = VISITING;
	q.push(start);
	while(!q.empty())
	{
		GraphNode *tmp = q.front();
		q.pop();
		std::vector<GraphNode*> adj = tmp->getAdjacent();
		for(std::size_t i = 0; i != adj.size(); ++i)
		{
			if(adj[i]->state == UNVISITED)
			{
				if(adj[i]->data == val) return true;
				adj[i]->state = VISITING;
				q.push(adj[i]);
			}
		}
		tmp->state = VISITED;
	}
	return false;
}








#endif /* GRAPH_H_ */
