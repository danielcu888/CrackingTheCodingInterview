//============================================================================
// Name        : Problem_1_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <cstddef>

using std::size_t;

void reverse(char *s);
size_t MyStrlen(char *s);
void MySwap(char *s, size_t i, size_t j);

int main()
{
	char s[] = {'t', 'e', 's', 't', '\0'};
	printf("%s\n", s);
	reverse(s);
	printf("%s\n", s);
	return 0;
}

void reverse(char *s)
{
	size_t len = MyStrlen(s);
	if(MyStrlen(s) <= 0) return;
	size_t i = 0, j = len - 1;
	while(i < j)
		MySwap(s, i++, j--);
}

size_t MyStrlen(char *s)
{
	size_t ret = 0;
	while(*s++)
		++ret;
	return ret;
}

void MySwap(char *s, size_t i, size_t j)
{
	char tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
}

