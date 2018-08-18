/*
 * main.cpp
 *
 *  Created on: Mar 6, 2012
 *      Author: danielcumberbatch
 */

#include <iostream>
#include "Person.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "ShellSort.h"

using std::endl; using std::cout;

int main()
{
	Person *array[4];
	array[0] = new Person(10);
	array[1] = new Person(5);
	array[2] = new Person(1);
	array[3] = new Person(65);

	//bubblesort(array, 4);
	//selectionsort_rec(array, 4);
	shellsort(array, 4);

	for(size_t i = 0; i != 4; ++i)
		cout << array[i]->age << " ";
	cout << endl;

	return 0;
}


