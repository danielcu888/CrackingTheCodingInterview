//============================================================================
// Name        : 1pt3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdlib>
#include <string>
#include <map>

using std::string; using std::map;

int main(int argc, char *argv[]) {
	return EXIT_SUCCESS;
}

// number of characters is small compared with range
bool is_permutation1(const string& s1, const string& s2) {
	// common sense checks
	if (s1.empty() || s2.empty())
		return false;
	const unsigned int l = s1.length();
	if (l != s2.length())
		return false;
	if (s1 == s2)
		return true;

	map<char, int> m;
	for (unsigned int i = 0; i != l; ++i)
		{
		++m[s1[i]]; --m[s2[i]];
		}
	map<char, int>::const_iterator e = m.end();
	for (map<char, int>::const_iterator it = m.begin(); it != e; ++it)
		if (it->second)
			return false;
	return true;
}

// number of characters is large compared with range
bool is_permutation2(const string& s1, const string& s2){
	// common sense checks
	if (s1.empty() || s2.empty())
		return false;
	const unsigned int l = s1.length();
	if (l != s2.length())
		return false;
	if (s1 == s2)
		return true;

	// ASCII
	int a[128];
	for (unsigned int i = 0; i != 128; ++i)
		a[i] = 0;
	for (unsigned int i = 0; i != l; ++i)
		{
		++a[static_cast<int>(s1[i])]; --a[static_cast<int>(s2[i])];
		}
	for (unsigned int i = 0; i != 128; ++i)
		if (a[i])
			return false;
	return true;
}
