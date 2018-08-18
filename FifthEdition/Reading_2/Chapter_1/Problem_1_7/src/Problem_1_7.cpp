//============================================================================
// Name        : Problem_1_7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

const size_t N = 3;
const size_t M = 4;

void display(int a[][M]);
void zeroed(int a[][M]);

int main()
{
	int a[N][M] = {{1,2,3,4},
				   {5,6,0,8},
				   {9,10,11,12}};
	display(a);
	cout << endl;
	zeroed(a);
	display(a);
	return 0;
}

void zeroed(int a[][M])
{
	bool row[N];
	bool col[M];
	for(size_t i = 0; i != N; ++i) row[i] = false;
	for(size_t i = 0; i != M; ++i) col[i] = false;

	for(size_t i = 0; i != N; ++i)
		for(size_t j = 0; j != M; ++j)
			if(a[i][j] == 0)
				row[i] = col[j] = true;

	for(size_t i = 0; i != N; ++i)
		for(size_t j = 0; j != M; ++j)
			if(row[i] || col[j]) a[i][j] = 0;
}

void display(int a[][M])
{
	for(size_t i = 0; i != N; ++i)
	{
		for(size_t j = 0; j != M; ++j)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
