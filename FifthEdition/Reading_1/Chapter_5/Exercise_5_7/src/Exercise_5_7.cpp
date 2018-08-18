//============================================================================
// Name        : Exercise_5_7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

int fetch(int a[], size_t sz, size_t i, size_t j)
{
	if(i >= sz) throw out_of_range("Error: attempt to access illegal index!");
	if(j >= 32) throw out_of_range("Error: attempt to access illegal bit!");

	return a[i] & (1 << j);
}

//Order n time complexity
int foo(int A[], size_t n)
{
	if(n == 0) throw invalid_argument("Error: zero-sized array!");
	int sum = 0;
	for(size_t i = 0; i <= n; ++i)
		for(size_t j = 0; j != 32; ++j) //assumes 32 bit ints
			sum += fetch(A, n + 1, i, j) ? pow(2.0, static_cast<double>(j)) : 0;
	int ex_total = n*(n+1)/2;
	return ex_total - sum;
}

int main()
{
	return 0;
}
