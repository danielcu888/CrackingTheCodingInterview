/*
 * main.c
 *
 *  Created on: Apr 30, 2012
 *      Author: danielcumberbatch
 */

#include <stdlib.h>

typedef enum bool {FALSE = 0, TRUE = 1} bool;

bool allUnique(char[]);

int main()
{
	return EXIT_SUCCESS;
}

bool allUnique(char s[])
{
	bool buffer[128];
	int i = 0;
	for(i = 0; i != 128; ++i)
		buffer[i] = FALSE;
	for(i = 0; i != strlen(s); ++i)
		if(buffer[s[i]] == TRUE)
			return FALSE;
		else
			buffer[s[i]] = TRUE;
	return TRUE;
}

