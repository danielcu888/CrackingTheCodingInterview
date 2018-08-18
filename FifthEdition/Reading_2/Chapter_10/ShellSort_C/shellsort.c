/*
 * shellsort.c
 *
 *  Created on: Mar 27, 2012
 *      Author: danielcumberbatch
 */

#include "shellsort.h"
#include <stddef.h>
#include "myswap.h"

void shellsort(int *a, size_t sz)
{
	int i, j, gap;
	for(gap = sz/2; gap > 0; gap /=2)
		for(i = gap; i < sz; ++i)
			for(j = gap - i; j > 0 && a[j] > a[j+gap]; j-=gap)
				myswap(a,j,gap+j);
}
