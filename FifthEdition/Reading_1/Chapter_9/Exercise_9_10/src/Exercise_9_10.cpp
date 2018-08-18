//============================================================================
// Name        : Exercise_9_10.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Box.h"
#include <vector>
#include <iostream>

using std::vector; using std::cout;
using std::endl;

int main()
{
	Box b1(10, 9, 8);
	Box b2(9, 8, 8);
	Box b3(8, 7, 6);
	Box b4(7, 6, 6);
	Box b5(6, 5, 3);
	Box b6(6, 4, 3);
	Box b7(4, 2, 2);
	Box b8(2, 1, 1);

	vector<Box> b;
	b.push_back(b1);
	b.push_back(b2);
	b.push_back(b3);
	b.push_back(b4);
	b.push_back(b5);
	b.push_back(b6);
	b.push_back(b7);
	b.push_back(b8);

	cout << "Original Stack is: " << endl;
	Box::display(cout, b);

	vector<Box> ret = Box::maxStack(b);

	cout << "The maximum stack is:" << endl;
	Box::display(cout, ret);

	return 0;
}
