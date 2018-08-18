/*
 * SelectionSort.h
 *
 *  Created on: Mar 6, 2012
 *      Author: danielcumberbatch
 */

#ifndef SELECTIONSORT_H_
#define SELECTIONSORT_H_

#include "Person.h"
#include <cstddef>

void selectionsort(Person *array[], std::size_t);
void selectionsort_rec(Person *array[], std::size_t);

#endif /* SELECTIONSORT_H_ */
