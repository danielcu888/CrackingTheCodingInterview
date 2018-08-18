/*
 * SelectionSort.cpp
 *
 *  Created on: Mar 6, 2012
 *      Author: danielcumberbatch
 */

#include "SelectionSort.h"
#include "Person.h"
#include "myswap.h"

void selectionsort(Person *array[], size_t sz)
{
	size_t i = 0;
	while(i < sz)
	{
		unsigned int min_age = array[i]->age;
		size_t min_idx = i;
		for(size_t j = i; j < sz; ++j)
		{
			min_idx = (array[j]->age < min_age) ? j : min_idx;
			min_age = array[min_idx]->age;
		}
		myswap(array + min_idx, array + i);
		++i;
	}
}

void selectionsort_rec(Person *array[], size_t sz)
{
	if(sz == 1) return;

	size_t i = 0;
	unsigned int min_age = array[i]->age;
	size_t min_idx = i;
	for(size_t j = i; j < sz; ++j)
	{
		min_idx = (array[j]->age < min_age) ? j : min_idx;
		min_age = array[min_idx]->age;
	}
	myswap(array + min_idx, array + i);

	return selectionsort(array + 1, sz - 1);
}




