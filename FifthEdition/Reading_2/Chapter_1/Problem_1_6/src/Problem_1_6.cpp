//============================================================================
// Name        : Problem_1_6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cstddef>
#include <iostream>

using std::size_t;
using std::cout; using std::endl;

const size_t N = 3;

void rotate(int a[][N]);
void display(int a[][N]);

int main()
{
	int a[N][N] = {{1,2,3},{4,5,6},{7,8,9}};
	display(a);
	cout << endl;
	rotate(a);
	display(a);

	return 0;
}

void rotate(int a[][N])
{
	for(size_t layer = 0; layer < N/2; ++layer)
	{
		size_t first = layer;
		size_t last = (N - 1) - layer;
		for(size_t i = first; i != last; ++i)
		{
			int offset = i - first;
			int top = a[first][i];
			a[first][i] = a[last - offset][first];
			a[last - offset][first] = a[last][last - offset];
			a[last][last - offset] = a[i][last];
			a[i][last] = top;
		}
	}
}

void display(int a[][N])
{
	for(size_t i = 0; i != N; ++i)
	{
		for(size_t j = 0; j != N; ++j)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
