//============================================================================
// Name        : Exercise_9_1_CPP_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using std::cout; using std::endl;

int wrapper(size_t);
void rec(size_t, size_t&, size_t);

int main()
{
	cout << wrapper(4) << endl;

	return 0;
}

int wrapper(size_t n)
{
	size_t count = 0;
	rec(n, count, 0);
	return count;
}

void rec(size_t n, size_t& count, size_t level)
{
	if(level == n)
		++count;
	else if(level < n)
		for(size_t i = 1; i <= 3; ++i)
			rec(n, count, level + i);
}
