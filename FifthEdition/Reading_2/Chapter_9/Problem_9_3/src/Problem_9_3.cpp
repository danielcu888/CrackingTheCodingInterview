//============================================================================
// Name        : Problem_9_3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

using std::vector; using std::cout; using std::endl;

int magicSearch(const vector<int>&, int, int);

int main()
{
	int a[] = {-3,-6,1,3,4,8,10};
	vector<int> v(a, a + sizeof(a)/sizeof(*a));
	cout << magicSearch(v, 0, v.size()-1) << endl;
	return 0;
}

int magicSearch(const vector<int>& v, int start, int end)
{
	if(start > end) return -1;
	if(v[start] == start) return start;
	while(v[start] < start)
		++start;
	return magicSearch(v, v[start], end);
}
