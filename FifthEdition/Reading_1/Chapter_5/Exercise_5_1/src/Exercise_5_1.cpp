//============================================================================
// Name        : Exercise_5_1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstddef>

using namespace std;

bool getBit(int num, size_t i)
{
	return ((1 << i) & num) != 0;
}

void setBit(int& num, size_t i)
{
	num |= (1 << i);
}

void clearBit(int& num, size_t i)
{
	num &= ~(1 << i);
}

void clearBitsMSBthroughI(int& num, size_t i)
{
	num &= (1 << i);
}

void clearBitsIthrough0(int& num, size_t i)
{
	num &= ~(1 << (i+1));
}

void updateBit(int& num, size_t i, bool val)
{
	num &= ~(1 << i);
	num |= (val << i);
}

void insert(int& N, int M, size_t i, size_t j)
{
	//clear N between bits i and j
	int mask = 0;
	for(size_t k = 0; k != (j - i); ++k)
	{
		mask <<= 1;
		mask += 1;
	}
	mask <<= i;
	N &= ~mask;

	//shift M to ith bit
	M <<= i;

	//switch on bits in range i to j that are on in M
	N |= M;
}

void displayBits(int x)
{
	for(int i = (1 << 27), count = 0; i > 0; i/=2, ++count)
		{
			if((count % 4) == 0)
				cout << " ";
			if((x & i) != 0)
				cout << "1";
			else
				cout << "0";
		}
	cout << endl;
}

int main()
{
	int N = (1 << 10);
	int M = 1 + 2 + 16;

	displayBits(N);
	displayBits(M);

	insert(N, M, 2, 6);

	displayBits(N);

	return 0;
}
