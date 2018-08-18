/*
 * main.cpp
 *
 *  Created on: Mar 28, 2012
 *      Author: danielcumberbatch
 */

#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>

using std::vector; using std::string;
using std::logic_error; using std::cout;
using std::endl;

vector<string> perm(const string&);

int main()
{
	vector<string> v = perm("xyz");
	for(vector<string>::size_type i = 0; i != v.size(); ++i)
		cout << v[i] << endl;
	return 0;
}

vector<string> perm(const string& s)
{
	if(s.empty()) throw logic_error("null string!");
	vector<string> ret;
	if(s.size() == 1)
	{
		ret.push_back(s);
		return ret;
	}

	for(string::const_iterator iter = s.begin(); iter != s.end(); ++iter)
	{
		string tmp = string(s.begin(), iter) + string(iter + 1, s.end());
		vector<string> tmpv = perm(tmp);
		for(vector<string>::size_type i = 0; i != tmpv.size(); ++i)
			ret.push_back(string(iter, iter+1) + tmpv[i]);
	}
	return ret;
}


