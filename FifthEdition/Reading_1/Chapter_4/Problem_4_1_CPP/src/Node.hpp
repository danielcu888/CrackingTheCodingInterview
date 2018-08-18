/*
 * Node.hpp
 *
 *  Created on: Jan 13, 2012
 *      Author: danielcumberbatch
 */

#ifndef NODE_HPP_
#define NODE_HPP_

struct Node
{
	Node(int _data = 0, Node *_left = 0, Node *_right = 0)
	: data(_data), left(_left), right(_right)
	{}

	int data;
	Node *left, *right;
};

#endif /* NODE_HPP_ */
