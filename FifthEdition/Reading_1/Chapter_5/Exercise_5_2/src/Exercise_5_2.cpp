//============================================================================
// Name        : Exercise_5_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdexcept>
#include <cmath>
using namespace std;

void displayBits(double x)
{
	if(x <= 0 || x >= 1)
		throw out_of_range("x is out of range!");

	cout << "ob0.";

	int i = 1;
	while(x > 0 && i < 32)
	{
		double d = pow(2.0, static_cast<double>(-i));
		x -= d;

		if(x >= 0)
			cout << "1";
		else
		{
			x += d;
			cout << "0";
		}
		++i;
	}
	cout << endl;

	if(i == 32)
		cout << "Error" << endl;
}

int main()
{
	for(double i = 1.0; i != 32.0; ++i)
	{
		double x = pow(2.0, -i);
		displayBits(x);
	}

	return 0;
}
