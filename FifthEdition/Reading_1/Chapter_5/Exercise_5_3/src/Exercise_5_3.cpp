//============================================================================
// Name        : Exercise_5_3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdexcept>
using namespace std;

size_t count(int x)
{
	size_t count_x = 0;
	if(x <= 0)
		throw out_of_range("Error: out of range!");

	for(int i = 128; i > 0; i /=2)
		count_x += ((x & i) > 0) ? 1 : 0;
	return count_x;
}

void next(int x)
{
	if(x == 0 || x == ~0)
		throw out_of_range("Error: invalid argument, x possesses max/min number of on bits.");

	size_t count_x = count(x);
	int tmp = x + 1;
	while(tmp < 128 && count(tmp) != count_x)
		++tmp;
	if(tmp == 128)
		cout << "Error: max limit reached!" << endl;
	else
		cout << tmp << endl;
	tmp = x - 1;
	while(tmp > 0 && count(tmp) != count_x)
		--tmp;
	if(tmp == 0)
		cout << "Error: max limit reached!" << endl;
	else
		cout << tmp << endl;
}

int main()
{
	int x = 10;
	next(x);
	return 0;
}
