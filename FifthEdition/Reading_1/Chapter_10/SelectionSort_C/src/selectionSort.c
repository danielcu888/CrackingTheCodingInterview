/*
 * selectionsort.cc
 *
 *  Created on: Mar 9, 2012
 *      Author: danielcumberbatch
 */

#include <stddef.h>
#include "mySwap.h"

void selectionSort(int *array, size_t sz)
{
	size_t i = 0;
	while(i < sz)
	{
		size_t min_idx = i;
		unsigned int min = array[i];
		size_t j;
		for(j = i; j != sz; ++j)
		{
			min_idx = (array[j] < min) ? j : min_idx;
			min = array[min_idx];
		}
		mySwap(array, i, min_idx);
		++i;
	}
}

void selectionSortRec(int *array, size_t sz, size_t level)
{
	if(level == sz) return;

	size_t min_idx = level;
	int min = array[level];
	size_t j;
	for(j = level; j != sz; ++j)
	{
		min_idx = (array[j] < min) ? j : min_idx;
		min = array[min_idx];
	}
	mySwap(array, level, min_idx);
	selectionSortRec(array, sz, level + 1);
}
