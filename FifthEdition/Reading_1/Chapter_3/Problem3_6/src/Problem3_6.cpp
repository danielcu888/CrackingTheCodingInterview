//============================================================================
// Name        : Problem3_6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stack>

using namespace std;

template <typename T>
void stackSort(stack<T>& s1)
{
	if(s1.empty()) return;
	stack<T> s3;
	s3.push(s1.top());
	s1.pop();

	while(!s1.empty())
	{
		if(s1.top() == s3.top() || s1.top() > s3.top())
			{
				s3.push(s1.top());
				s1.pop();
			}
		else //i.e., s1.top() < s3.top()
		{
			T tmp = s1.top();
			s1.pop();
			while(!s3.empty() && s3.top() > tmp)
				{
					s1.push(s3.top());
					s3.pop();
				}
			s3.push(tmp);
		}
	}
	s1 = s3;
}

template <typename T>
void display(stack<T>& s1)
{
	while(!s1.empty())
	{
		cout << s1.top() << endl;
		s1.pop();
	}
	cout << endl;
}

int main(int argc, char **argv)
{
	stack<int> s1;
	s1.push(10);
	s1.push(2);
	s1.push(5);
	s1.push(18);
	s1.push(20);
	s1.push(1);
	s1.push(4);

	stackSort(s1);

	display(s1);

	return 0;
}
