/*
 * main.cpp
 *
 *  Created on: Mar 27, 2012
 *      Author: danielcumberbatch
 */

#include <map>
#include <cstddef>
#include <iostream>

using std::map; using std::size_t;
using std::cout; using std::endl;

int numberOfWays(int, map<int, size_t>&);

int main()
{
	map<int, size_t> m;
	const size_t N = 4;
	cout << numberOfWays(N, m) << endl;

	return 0;
}

int numberOfWays(int n, map<int, size_t>& m)
{
	map<int, size_t>::iterator iter = m.find(n);
	if(iter != m.end())
	{
		return m[n];
	}
	size_t q = 0;
	if(n < 0)
		return 0;
	else if(n == 0)
		q = 1;
	else
		q = numberOfWays(n-1, m) + numberOfWays(n-2, m) + numberOfWays(n-3, m);
	m[n] = q;
	return q;
}

