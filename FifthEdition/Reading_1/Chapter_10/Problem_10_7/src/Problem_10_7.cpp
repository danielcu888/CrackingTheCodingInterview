//============================================================================
// Name        : Problem_10_7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include "Person.h"
#include "constructTower.h"

using namespace std;

int main()
{
	list<Person> ppl;
	ppl.push_back(Person(65,100));
	ppl.push_back(Person(70,150));
	ppl.push_back(Person(56,90));
	ppl.push_back(Person(75,190));
	ppl.push_back(Person(60,95));
	ppl.push_back(Person(68,110));

	constructTower(ppl);

	return 0;
}
