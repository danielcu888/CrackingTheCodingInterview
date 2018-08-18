//============================================================================
// Name        : Problem_1_1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <iostream>

using std::string; using std::cout;
using std::endl;

bool isAllUnique(const string&);
bool isAllUnique2(const string&);

int main()
{
	string s = "teststring";
	cout << isAllUnique(s) << endl;

	return 0;
}

bool isAllUnique(const string& s)
{
	bool c[128];
	for(string::size_type i = 0; i != s.size(); ++i)
	{
		char p = s[i];
		if(c[p]) return false;
		c[p] = true;
	}
	return true;
}

bool isAllUnique2(const string& s)
{
	if(s.size() > 128) return false;

	int checker = 0;
	for(string::size_type i = 0; i != s.size(); ++i)
	{
		int j = s[i] - 'a';
		if(checker & j) return false;
		checker |= (1 << j);
	}
	return true;
}

