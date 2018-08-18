/*
 * BitsFuncs.h
 *
 *  Created on: Mar 22, 2012
 *      Author: danielcumberbatch
 */

#ifndef BITSFUNCS_H_
#define BITSFUNCS_H_

#include <cstddef>

bool getBit(int x, std::size_t n)
{
	return (x & (1 << n));
}

void setBit(int x, std::size_t n)
{
	x |= (1 << n);
}

void clearBit(int x, std::size_t n)
{
	x &= ~(1 << n);
}

void clearBitsMSthroughN(int x, std::size_t n)
{
	x &= (~0) >> n;
}

void clearBitsNthrough0(int x, std::size_t n)
{
	x &= ~((~0) >> n);
}

void updateBit(int x, std::size_t n, bool b)
{
	int val = b ? 1 : 0;
	x = (x & ~(1 << n)) | (val << n);
}

#endif /* BITSFUNCS_H_ */
