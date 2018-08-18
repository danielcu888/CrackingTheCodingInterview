//============================================================================
// Name        : Problem_1_5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <cstddef>
#include <iostream>

using std::string; using std::size_t;
using std::cout; using std::endl;

const string compress(const string& a);
const string size_tTostring(size_t i);
void MyReverse(string& s);

int main()
{
	string a("aaaaaaaaaabcccccaaa");
	cout << compress(a) << endl;

	return 0;
}

const string compress(const string& a)
{
	string buffer;
	size_t beg = 0, end = 0;
	while(beg < a.size())
	{
		while(a[beg] == a[end])
			++end;
		buffer += a[beg];
		if((end - beg) > 1)
			//buffer += ((end - beg) + '0');
			buffer += size_tTostring(end - beg);
		beg = end;
	}
	return buffer;
}

const string size_tTostring(size_t i)
{
	if(i == 0) return "0";
	string ret;
	while(i > 0)
	{
		ret += (i % 10) + '0';
		i /= 10;
	}
	MyReverse(ret);
	return ret;
}

void MyReverse(string& s)
{
	if(s.size() <= 1) return;
	string::size_type i = 0, j = s.size() - 1;
	while(i < j)
	{
		char tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		++i; --j;
	}
}

