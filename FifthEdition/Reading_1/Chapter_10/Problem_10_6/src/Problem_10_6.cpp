//============================================================================
// Name        : Problem_10_6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "findElement.h"

using namespace std;

int main()
{
	vector<vector<int> > matrix;
	int a[4] = {15,20,40,85};
	matrix.push_back(vector<int>(a, a + sizeof(a)/sizeof(*a)));
	int b[4] = {20,35,80,95};
	matrix.push_back(vector<int>(b, b+sizeof(b)/sizeof(*b)));
	int c[4] = {30,55,95,105};
	matrix.push_back(vector<int>(c, c+sizeof(c)/sizeof(*c)));
	int d[4] = {40,80,100,120};
	matrix.push_back(vector<int>(d, d+sizeof(d)/sizeof(*d)));

	cout << findElement(matrix, 54) << endl;

	return 0;
}
