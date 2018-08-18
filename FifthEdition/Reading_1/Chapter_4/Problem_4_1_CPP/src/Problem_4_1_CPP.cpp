//============================================================================
// Name        : Problem_4_1_CPP.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Node.hpp"
#include <cmath>

using namespace std;

//recursive algorithm
int check(bool& bal, Node *curr)
{
	if(!curr) return 0;
	if(!bal) return 0;
	int leftNum = check(bal, curr->left);
	int rightNum = check(bal, curr->right);
	bal = bal && (abs(leftNum - rightNum) <= 1);
	return leftNum + rightNum + 1;
}

//warpper
bool isTreeBalanced(Node *head)
{
	bool isBal = true;
	check(isBal, head);
	return isBal;
}

void preOrderTrav(Node *curr)
{
	if(!curr) return;
	cout << curr->data << endl;
	preOrderTrav(curr->left);
	preOrderTrav(curr->right);
}

int main()
{
	Node* unbal = new Node(100, new Node(50, new Node(25, 0, 0), new Node(75, 0, 0)),
			new Node(150, new Node(125, new Node(110, 0, 0), 0), 0));

	Node* bal = new Node(100, new Node(50, new Node(25, 0, 0), new Node(75, 0, 0)),
			new Node(150, new Node(125, 0, 0), new Node(175, 0, 0)));

	preOrderTrav(unbal);
	preOrderTrav(bal);

	cout << isTreeBalanced(unbal) << endl;
	cout << isTreeBalanced(bal) << endl;

	return 0;
}
