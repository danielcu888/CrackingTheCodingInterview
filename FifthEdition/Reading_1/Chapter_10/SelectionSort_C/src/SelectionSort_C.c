/*
 ============================================================================
 Name        : SelectionSort_vC.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include "selectionSort.h"

int main()
{
	int array[4] = {1,4,9,2};
	selectionSort(array, 4);

	size_t i;
	for(i = 0; i != 4; ++i)
		printf("%d\t", array[i]);
	printf("\n");

	return 0;
}
