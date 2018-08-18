/*
 * shellSort.c
 *
 *  Created on: Mar 9, 2012
 *      Author: danielcumberbatch
 */

#include <stddef.h>
#include "mySwap.h"
#include "shellSort.h"

void shellSort(int *array, int n)
{
	int i, j, gap;
	for(gap = n/2; gap > 0; gap /=2)
		for(i = gap; i < n; ++i)
			for(j = i - gap; j>=0 && array[j] > array[gap + j]; j-=gap)
				mySwap(array, j, gap + j);
}

