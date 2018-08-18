/*
 * main.cpp
 *
 *  Created on: Mar 28, 2012
 *      Author: danielcumberbatch
 */

#include <vector>
#include <string>
#include <iostream>

using std::cout; using std::endl;
using std::vector; using std::string;

vector<string> foo(const string&);

int main()
{
	string s = "wxyz";
	vector<string> v = foo(s);
	for(vector<string>::const_iterator iter = v.begin();
		iter != v.end(); ++iter)
		cout << *iter << endl;

	return 0;
}

vector<string> foo(const string& s)
{
	vector<string> tmp;
	if(s.empty()) return tmp;
	if(s.size() > 1)
	{
		string stmp = string(s.begin() + 1, s.end());
		tmp = foo(stmp);

		vector<string>::size_type sz = tmp.size();
		for(vector<string>::size_type i = 0; i != sz; ++i)
			tmp.push_back(s[0] + tmp[i]);
	}
	tmp.push_back(s.substr(0,1));
	return tmp;
}
