//============================================================================
// Name        : Exercise_9_2_b_CPP.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <cstddef>

using std::string; using std::out_of_range;
using std::cout; using std::endl;
using std::vector; using std::size_t;

void recursive(string& path, int num_rights, int num_downs, int x, int y, vector<string>& v)
{
	if(num_rights == x && num_downs == y)
		v.push_back(path);
	else if(num_rights < x && num_downs == y)
	{
		string tmp = path + "r";
		recursive(tmp, num_rights+1, num_downs, x, y, v);
	}
	else if(num_rights == x && num_downs < y)
	{
		string tmp = path + "d";
		recursive(tmp, num_rights, num_downs+1, x, y, v);
	}
	else
	{
		string tmp1 = path + "d";
		string tmp2 = path + "r";
		recursive(tmp1, num_rights, num_downs+1, x, y, v);
		recursive(tmp2, num_rights+1, num_downs, x, y, v);
	}
}

bool isValid(const string& s, const vector<vector<int> >& hotSpots)
{
	int curr_x = 0, curr_y = 0;
	size_t readPos = 0;
	while(readPos != s.size())
	{
		if(s[readPos++] == 'd')
			++curr_y;
		else
			++curr_x;

		for(vector<vector<int> >::size_type i = 0; i != hotSpots.size(); ++i)
			if(hotSpots[i][0] == curr_x && hotSpots[i][1] == curr_y)
				return false;
	}
	return true;
}

string wrapper(int x, int y, const vector<vector<int> >& hotSpots)
{
	if(x < 1 || y < 1) throw out_of_range("illegal grid dimensions!");

	string path;
	vector<string> v;

	recursive(path, 0, 0, 2, 2, v);

	for(vector<string>::size_type i = 0; i != v.size(); ++i)
		if(isValid(v[i], hotSpots))
			return v[i];

	return "No valid paths found!";
}

int main()
{
	vector<vector<int> > hotSpots;

	int a_tmp[] = {0,1};
	vector<int> tmp(a_tmp, a_tmp + sizeof(a_tmp)/sizeof(*a_tmp));
	hotSpots.push_back(tmp);

	cout << wrapper(2,2,hotSpots) << endl;

	return 0;
}
