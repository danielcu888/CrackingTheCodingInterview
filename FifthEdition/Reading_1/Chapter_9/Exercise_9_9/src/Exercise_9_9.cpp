//============================================================================
// Name        : Exercise_9_9.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <vector>
#include <iostream>
#include <fstream>

using std::vector; using std::cout;
using std::endl; using std::ostream;
using std::ofstream;

const size_t DIM = 8;
//ofstream outfile("/Users/danielcumberbatch/Desktop/out.txt");

int wrapper();
int rec(vector<vector<bool> >&, int&, int);
vector<vector<bool> > construct();
bool isValid(const vector<vector<bool> >& used, vector<bool>::size_type x, vector<vector<bool> >::size_type y);
void display(ostream&, const vector<vector<bool> >& v);

int main()
{
	cout << wrapper() << endl;
	return 0;
}

void display(ostream& os, const vector<vector<bool> >& v)
{
	for(size_t i = 0; i != v.size(); ++i)
	{
		for(size_t j = 0; j != v[i].size(); ++j)
			if(v[i][j]) os << " T ";
			else os << " F ";
		os << endl;
	}
	os << endl;
}

int wrapper()
{
	vector<vector<bool> > used = construct();
	int count = 0;
	return rec(used, count, 0);
}

int rec(vector<vector<bool> >& used, int& count, int level)
{
	if(level == 8)
	{
		//display(cout, used);
		++count;
		return count;
	}

	for(vector<bool>::size_type x = 0; x != DIM; ++x)
	{
		if(isValid(used, x, level))
		{
			used[level][x] = true;
			rec(used, count, level + 1);
			used[level][x] = false;
		}
	}

	return count;
}

vector<vector<bool> > construct()
{
	vector<vector<bool> > ret(8);
	for(vector<vector<bool> >::size_type i = 0; i != DIM; ++i)
		ret[i] = vector<bool>(DIM, false);
	return ret;
}

bool isValid(const vector<vector<bool> >& used, vector<bool>::size_type x, vector<vector<bool> >::size_type y)
{
	int row = static_cast<int>(y), col = static_cast<int>(x);
	bool up, up_rt, rt, dn_rt, dn, dn_lt, lt, up_lt;

	//check up
	while(row >= 0)
	{
		up = used[row--][col];
		if(up) break;
	}
	row = static_cast<int>(y), col = static_cast<int>(x);

	//check up-right
	while(row >= 0 && col < static_cast<int>(DIM))
	{
		up_rt = used[row--][col++];
		if(up_rt) break;
	}
	row = static_cast<int>(y), col = static_cast<int>(x);

	//check right
	while(col < static_cast<int>(DIM))
	{
		rt = used[row][col++];
		if(rt) break;
	}
	row = static_cast<int>(y), col = static_cast<int>(x);

	//check down-right
	while(row < static_cast<int>(DIM) && col < static_cast<int>(DIM))
	{
		dn_rt = used[row++][col++];
		if(dn_rt) break;
	}
	row = static_cast<int>(y), col = static_cast<int>(x);

	//check down
	while(row < static_cast<int>(DIM))
	{
		dn = used[row++][col];
		if(dn) break;
	}
	row = static_cast<int>(y), col = static_cast<int>(x);

	//check down-left
	while(row < static_cast<int>(DIM) && col >= 0)
	{
		dn_lt = used[row++][col--];
		if(dn_lt) break;
	}
	row = static_cast<int>(y), col = static_cast<int>(x);

	//check left
	while(col >= 0)
	{
		lt = used[row][col--];
		if(lt) break;
	}
	row = static_cast<int>(y), col = static_cast<int>(x);

	//check up-left
	while(row >= 0 && col >= 0)
	{
		up_lt = used[row--][col--];
		if(up_lt) break;
	}

	return !(up || up_rt || rt || dn_rt || dn || dn_lt || lt || up_lt);
}

