//============================================================================
// Name        : Problem_1_3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

using std::cout; using std::endl;
using std::string;

bool isPermutation(const string& s1, const string& s2);

int main()
{
	string s1("test1");
	string s2("test2");
	string s3("es1tt");

	cout << isPermutation(s1, s2) << endl;
	cout << isPermutation(s1, s3) << endl;

	return 0;
}

bool isPermutation(const string& s1, const string& s2)
{
	if(s1.size() != s2.size()) return false;
	int a[128];
	for(size_t i = 0; i != 128; ++i) a[i] = 0;
	for(string::size_type i = 0; i != s1.size(); ++i)
	{
		++a[s1[i]]; --a[s2[i]];
	}
	for(size_t i = 0; i != 128; ++i)
		if(a[i]) return false;
	return true;
}
