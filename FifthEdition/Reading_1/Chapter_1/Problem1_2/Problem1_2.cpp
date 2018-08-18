/*
 * Problem1_2.cpp
 *
 *  Created on: Dec 14, 2011
 *      Author: danielcumberbatch
 */

#include <cstdio>
#include <cstddef>
#include <cstring>
#include <string>
#include <iostream>

using std::string;
using std::cout; using std::endl;

//C implementation, O(strlen(str)) time complexity, O(1) space complexity
void reverse(char* str)
{
	if(!str) return;

	char *beg = str, *end = str;
	while(*end != '\0')
		++end;
	--end;
	while((end - beg) > 0)
	{
		char tmp = *beg;
		*beg++ = *end;
		*end-- = tmp;
	}
}

//C++ implementation, O(str.size()) time complexity, O(1) space complexity
void reverse2(string& str)
{
	size_t beg = 0, end = str.size() - 1;
	while(beg < end)
	{
		char tmp = str[beg];
		str[beg] = str[end];
		str[end] = tmp;
		++beg; --end;
	}
}

int main()
{
	char test[] = {'a','b','c','\0'};
	string test2 = "ahsdksajhdkjashkdja";
	reverse(test);
	printf("%s\n", test);
	reverse2(test2);
	cout << test2 << endl;
	return 0;
}
