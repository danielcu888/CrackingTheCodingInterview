//============================================================================
// Name        : 1pt1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <map>
#include <iostream>

using std::string;
using std::map;
using std::cout; using std::endl;

bool all_unique_chars1(const string&);
bool all_unique_chars2(const string&);
bool all_unique_chars3(const string&);
bool all_unique_chars4(const string&);

int main(int argc, char *argv[])
	{
	const string test1("abcdefghijklmnopqrstuvwxyz");
	if (all_unique_chars4(test1))
		cout << "all unique chars" << endl;
	else
		cout << "not all unique chars" << endl;

	return 0;
	}

bool all_unique_chars1(const string& s)
	{
	if (s.empty())
		return true;
	if (s.length() > 128)
		return false;
	bool a[128];
	for(unsigned int i = 0; i != 128; ++i)
		a[i] = 0;
	string::const_iterator e = s.end();
	for (string::const_iterator iter = s.begin(); iter != e; ++iter)
		if (a[static_cast<unsigned int>(*iter)])
			return false;
		else
			a[static_cast<unsigned int>(*iter)] = true;
	return true;
	}

bool all_unique_chars2(const string& s)
	{
	if (s.empty())
		return true;
	if (s.length() > 128)
		return false;
	map<char, string::size_type> m;
	string::const_iterator e = s.end();
	for (string::const_iterator iter = s.begin(); iter != e; ++iter)
		if(m.find(*iter) == m.end())
			++m[*iter];
		else
			return false;
	return true;
	}

bool all_unique_chars3(const string& s)
	{
	if (s.empty())
		return true;
	if (s.length() > 128)
		return false;
	map<char, string::size_type> m;
	string::const_iterator e = s.end();
	for (string::const_iterator iter = s.begin(); iter != e; ++iter)
		++m[*iter];
	for (map<char, string::size_type>::const_iterator iter = m.begin(); iter != m.end(); ++iter)
		if (iter->second > 1)
			return false;
	return true;
	}

bool all_unique_chars4(const string& s)
	{
	if (s.empty())
		return true;
	if (s.length() > 26)
		return false;
	unsigned long bv = 0UL; //64 bit vector
	string::const_iterator e = s.end();
	for (string::const_iterator iter = s.begin(); iter != e; ++iter)
		if ((1 << *iter) & bv)
			return false;
		else
			bv |= (1 << *iter);
	return true;
	}
