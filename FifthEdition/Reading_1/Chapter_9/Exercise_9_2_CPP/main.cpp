/*
 * main.cpp
 *
 *  Created on: Feb 8, 2012
 *      Author: danielcumberbatch
 */

#include <stdexcept>
#include <iostream>

using std::out_of_range;
using std::cout;
using std::endl;

int recursive(int n)
{
	return n > 1 ? n*recursive(n-1) : n;
}

int factorial(int n)
{
	if(n < 0) throw out_of_range("factorials of negative numbers are infinite!");
	return recursive(n);
}

int num_paths(int x, int y)
{
	if(x < 1 || y < 1) throw out_of_range("Invalid Grid Dimensions!");
	return factorial(x+y)/(factorial(x)*factorial(y));
}

int main()
{
	cout << num_paths(2,2) << endl;
	return 0;
}

