/*
 * mySwap.cc
 *
 *  Created on: Mar 9, 2012
 *      Author: danielcumberbatch
 */

#include <stddef.h>

void mySwap(int *array, size_t i, size_t j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}


