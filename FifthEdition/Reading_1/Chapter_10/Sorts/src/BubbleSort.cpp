//============================================================================
// Name        : BubbleSort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "BubbleSort.h"
#include "Person.h"
#include "myswap.h"

#include <cstddef>

using std::size_t;

void bubblesort(Person *array[], size_t sz)
{
	bool swapped;
	do {
		size_t i = 0;
		swapped = false;
		while(i < sz)
		{
			if(i < sz-1 && array[i]->age > array[i+1]->age)
			{
				myswap(array + i, array + i + 1);
				swapped = true;
			}
			++i;
		}
	} while(swapped);
}
