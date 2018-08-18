/*
 * main.cpp
 *
 *  Created on: Mar 27, 2012
 *      Author: danielcumberbatch
 */

#include <cstddef>
#include <iostream>

using std::cout; using std::endl;
using std::size_t;

size_t numberOfWays(int);
void numberOfWays_rec(int, size_t&);

int main()
{
	const size_t N = 5;
	size_t num = numberOfWays(N);
	cout << num << endl;

	return 0;
}

size_t numberOfWays(int n)
{
	if(n < 1) return 0;
	size_t count = 0;
	numberOfWays_rec(n, count);
	return count;
}

void numberOfWays_rec(int n, size_t& count)
{
	if(n == 0)
	{
		++count;
		return;
	}
	if(n < 0) return;

	numberOfWays_rec(n-1, count);
	numberOfWays_rec(n-2, count);
	numberOfWays_rec(n-3, count);
}
