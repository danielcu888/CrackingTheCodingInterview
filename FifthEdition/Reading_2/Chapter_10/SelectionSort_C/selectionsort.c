/*
 * selectionsort.c
 *
 *  Created on: Mar 27, 2012
 *      Author: danielcumberbatch
 */

#include "selectionsort.h"
#include "myswap.h"
#include <stddef.h>

void selectionsort(int *a, int sz)
{
	size_t i = 0;
	while(i < sz)
	{
		size_t imin = i;
		int min = a[imin];
		size_t j;
		for(j = i; j != sz; ++j)
			if(a[j] < min)
			{
				imin = j;
				min = a[j];
			}
		myswap(a, i, imin);
		++i;
	}
}
