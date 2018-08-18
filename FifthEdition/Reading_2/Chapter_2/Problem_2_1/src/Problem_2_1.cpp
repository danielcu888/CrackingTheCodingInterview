//============================================================================
// Name        : Problem_2_1.cpp
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
	Node* head = new Node(5, new Node(10, new Node(6, new Node(8, new Node(5, new Node(4, new Node(10)))))));
	display(head);
	deleteDup2(head);
	display(head);
	return 0;
}
