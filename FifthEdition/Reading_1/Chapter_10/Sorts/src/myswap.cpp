/*
 * myswap.cpp
 *
 *  Created on: Mar 6, 2012
 *      Author: danielcumberbatch
 */

#include "myswap.h"

void myswap(Person **p1, Person **p2)
{
	Person *tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}



