//============================================================================
// Name        : 1pt4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdio>
#include <cstdlib>
#include <cstring>

static const int N = 1000;
char a[N];

bool replace(char a[], const char *rep);

int main(int argc, char *argv[])
	{
	const char b[] = {'M','r',' ','J','o','h','n',' ','S','m','i','t','h',' ',' ',' ','\0'};
	const int len_b = strlen(b) + 1;
	for (int i = 0; i < len_b; ++i)
		a[i] = b[i];
	printf("The input: %s\n", a);
	replace(a, "%20");
	printf("The output: %s\n", a);

	return EXIT_SUCCESS;
	}

bool replace(char *a, const char *rep)
	{
	if (!a || !rep) return false;
	const int len_rep = strlen(rep);
	if (len_rep <= 0) return false;

	const int len_used = strlen(a);
	if (len_used <= 0) return false;

	unsigned int count = 0;
	int src = len_used;
	int dest = N - 1;
	while (src >= 0)
		{
		const char ch = a[src--];
		if (ch == ' ')
			{
			++count;
			for(int i = 0; i < len_rep; ++i)
				a[dest--] = *(rep + len_rep - 1 - i);
			}
		else
			a[dest--] = ch;
		}
	++dest;

	const unsigned int new_len = count*len_rep + len_used;
	for(unsigned int i = 0; i < new_len; ++i)
		a[i] = a[i+dest];

	return true;
	}
