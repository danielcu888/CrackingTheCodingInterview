/*
 * main.cpp
 *
 *  Created on: Feb 8, 2012
 *      Author: danielcumberbatch
 */

#include <stdexcept>
#include <string>
#include <iostream>

using std::out_of_range;
using std::string;
using std::cout; using std::endl;

void recursive(string& path, int num_steps, int n, int& count)
{
	//base case
	if(num_steps == n)
	{
		cout << path << endl;
		++count;
	}
	else if(num_steps < n)
	{
		//recursive case
		string tmp1 = path + "1";
		string tmp2 = path + "2";
		string tmp3 = path + "3";
		recursive(tmp1, num_steps + 1, n, count);
		recursive(tmp2, num_steps + 2, n, count);
		recursive(tmp3, num_steps + 3, n, count);
	}
}

int wrapper(int n)
{
	if(n < 1) throw out_of_range("number steps must be  > 1");
	int count = 0;
	string path;
	recursive(path, 0, n, count);
	return count;
}

int main()
{
	cout << "\nNumber of ways to get up the stairs = " << wrapper(3) << endl;
	return 0;
}

