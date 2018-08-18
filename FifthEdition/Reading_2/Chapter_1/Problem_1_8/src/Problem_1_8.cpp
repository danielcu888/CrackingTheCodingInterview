//============================================================================
// Name        : Problem_1_8.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

bool isSubString(const string& s1, const string& s2);
bool isRotation(const string& s1, const string& s2);

int main()
{
	return 0;
}

bool isRotation(const string& s1, const string& s2)
{
	string tmp = s2 + s2;
	return isSubString(s1, tmp);
}
