/*
 * ShellSort.cpp
 *
 *  Created on: Mar 6, 2012
 *      Author: danielcumberbatch
 */

#include "ShellSort.h"
#include "Person.h"
#include "myswap.h"

void shellsort(Person *array[], int n)
{
	int gap, i, j;
	for(gap = n/2; gap > 0; gap /=2)
		for(i = gap; i < n; ++i)
			for(j = i-gap; j >= 0 && array[j]->age > array[j+gap]->age; j-=gap)
				myswap(array + j, array + j + gap);
}


