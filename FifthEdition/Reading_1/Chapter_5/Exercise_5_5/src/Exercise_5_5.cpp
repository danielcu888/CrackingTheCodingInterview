//============================================================================
// Name        : Exercise_5_5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

size_t foo(int a, int b)
{
	int count = 0;
	for(int tmp = a^b; tmp > 0; tmp >>= 1)
		count += tmp & 1;
	return count;
}

int main()
{
	cout << foo(31,14) << endl;

	return 0;
}
