//============================================================================
// Name        : Problem_1_4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <cstddef>

using std::size_t;

void replaceSpaces(char *s);
size_t MyStrlen(char *s);

int main()
{
	char s[] = {'M', 'r', ' ', 'J', 'o', 'h', 'n', ' ', 'S', 'm', 'i', 't', 'h', ' ', ' ', ' ', ' ', '\0', ' ', ' '};
	printf("%s\n", s);
	replaceSpaces(s);
	printf("%s\n", s);
	return 0;
}

void replaceSpaces(char *s)
{
	size_t len = MyStrlen(s);
	if(len == 0) return;

	size_t num = 0;
	for(size_t i = 0; i != len; ++i)
		if(s[i] == ' ') ++num;
	if(num == 0) return;

	for(size_t i = len + 1; i <= len + num*3; ++i)
		s[i] = '\0';

	int readPos = len - 1;
	len += num*(3-1);
	size_t writePos = len - 1;

	while(readPos >= 0)
	{
		if(s[readPos] == ' ')
		{
			s[writePos--] = '0';
			s[writePos--] = '2';
			s[writePos--] = '%';
		}
		else
			s[writePos--] = s[readPos];
		--readPos;
	}
}

size_t MyStrlen(char *s)
{
	size_t ret = 0;
	while(*s++)
		++ret;
	return ret;
}
