/*
 * main.cpp
 *
 *  Created on: Apr 30, 2012
 *      Author: danielcumberbatch
 */

void reverse(char *);

int main()
{
	return 0;
}

void reverse(char *str)
{
	char *beg = str;
	char *end = beg;
	while(str[end] != '\0')
		++end;
	--end;
	while(beg < end)
	{
		char tmp = str[beg];
		str[beg] = str[end];
		str[end] = tmp;
		++beg;
		--end;
	}
}
