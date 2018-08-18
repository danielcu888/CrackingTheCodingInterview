//============================================================================
// Name        : Problem_2_5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "Node.h"

int main()
{
	Node* head1 = new Node(7, new Node(1, new Node(6)));
	display(head1);
	Node* head2 = new Node(5, new Node(9, new Node(2)));
	display(head2);

	Node *result = sum2(head1, head2);
	display(result);

	return 0;
}
