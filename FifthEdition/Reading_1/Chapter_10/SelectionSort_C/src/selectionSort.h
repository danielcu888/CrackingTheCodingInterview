/*
 * selectionSort.h
 *
 *  Created on: Mar 9, 2012
 *      Author: danielcumberbatch
 */

#ifndef SELECTIONSORT_H_
#define SELECTIONSORT_H_

/*
 * Selection sort traverses array,
 * swapping smallest element with ith
 * element on ith pass.
 */
void selectionSort(int *, size_t);
void selectionSortRec(int *, size_t, size_t);

#endif /* SELECTIONSORT_H_ */
