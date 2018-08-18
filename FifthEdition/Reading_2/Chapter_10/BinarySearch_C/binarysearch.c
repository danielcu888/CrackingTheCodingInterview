/*
 * binarysearch.c
 *
 *  Created on: Mar 27, 2012
 *      Author: danielcumberbatch
 */

#include "binarysearch.h"

int binarysearch(int *a, int start, int end, int val)
{
	if(start > end) return -1;
	int mid = (start + end)/2;
	if(a[mid] == val) return mid;
	else if(a[mid] < val)
		return binarysearch(a, mid + 1, end, val);
	else
		return binarysearch(a, start, mid - 1, val);
}
