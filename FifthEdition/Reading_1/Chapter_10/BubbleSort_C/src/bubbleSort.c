/*
 * bubbleSort.c
 *
 *  Created on: Mar 9, 2012
 *      Author: danielcumberbatch
 */

#include "bubbleSort.h"
#include <stddef.h>
#include "mySwap.h"

enum BOOLEAN {FALSE, TRUE};

void bubbleSort(int *array, size_t sz)
{
	enum BOOLEAN flag;
	do {
		flag = FALSE;
		size_t i;
		for(i = 0; i < sz - 1; ++i)
			if(array[i] > array[i + 1])
			{
				mySwap(array, i, i+1);
				flag = TRUE;
			}
	} while(flag);
}



