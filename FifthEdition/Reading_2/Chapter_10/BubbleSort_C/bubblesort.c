/*
 * bubblesort.c
 *
 *  Created on: Mar 27, 2012
 *      Author: danielcumberbatch
 */

#include "bubblesort.h"
#include "myswap.h"
#include <stddef.h>

enum BOOL {FALSE = 0, TRUE = 1};

void bubblesort(int *a, size_t sz)
{
	enum BOOL flag = FALSE;
	do {
		size_t i;
		for(i = 0; i != sz - 1; ++i)
			if(a[i+1] < a[i])
			{
				myswap(a, i, i+1);
				flag = TRUE;
			}
	} while(flag);
}
