//============================================================================
// Name        : 1pt2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstdlib>
#include <cstring>
#include <iostream>

enum BOOL {FALSE = 0, TRUE = 1};

BOOL reverse(char* str);
BOOL print_details(char *str);

int main(int argc, char *argv[])
	{
	char *test0 = NULL;
	char test1[] = {'s', 't', 'r', 'i', 'n', 'g', '\0'};
	char test2[] = {'\0'};
	char test3[] = {'p', '\0'};
	char test4[] = {'o', 'o', 'p', '\0'};

	print_details(test0);
	print_details(test1);
	print_details(test2);
	print_details(test3);
	print_details(test4);

	return EXIT_SUCCESS;
	}

BOOL print_details(char *str)
	{
	if (!str)
		{
		printf("ERROR: NULL string\n");
		return FALSE;
		}
	printf("The reverse of %s is ", str);
	const BOOL b = reverse(str);
	if (b == TRUE)
		printf("%s", str);
	else
		printf("undefined");
	printf("\n");

	return TRUE;
	}

BOOL reverse(char* str)
	{
	if (!str)
		return FALSE;
	const size_t len = strlen(str);
	if (str[len] != '\0')
		return FALSE;
	if (len <= 1)
		return TRUE;
	char *beg = str, *end = str + len - 1;
	while (beg < end)
		{
		const char tmp = *beg;
		*beg = *end;
		*end = tmp;
		++beg; --end;
		}

	return TRUE;
	}
