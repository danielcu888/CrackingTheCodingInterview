/*
 * myswap.c
 *
 *  Created on: Mar 27, 2012
 *      Author: danielcumberbatch
 */

#include "myswap.h"

void myswap(int *a, size_t i, size_t j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}
