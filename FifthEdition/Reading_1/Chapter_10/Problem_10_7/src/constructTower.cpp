/*
 * constructTower.cpp
 *
 *  Created on: Mar 12, 2012
 *      Author: danielcumberbatch
 */

#include "constructTower.h"
#include "Person.h"

#include <cstddef>
#include <stack>
#include <list>
#include <iostream>

using std::list; using std::size_t;
using std::stack; using std::cout;
using std::endl;

bool isValid(Person&, Person&);
void constructTower_rec(list<Person>&, stack<Person*>&, stack<Person*>&, size_t&, size_t);

void constructTower(list<Person>& ppl)
{
	if(ppl.empty()) return;
	stack<Person*> tower;
	stack<Person*> max_tower;
	size_t max_ht = 0;
	constructTower_rec(ppl, tower, max_tower, max_ht, 0);
	cout << "The longest tower is length " << max_ht << " and includes from top to bottom:" << endl;
	while(!max_tower.empty())
	{
		cout << "(" << max_tower.top()->weight() << ", " << max_tower.top()->height() << ")" << " ";
		max_tower.pop();
	}
	cout << endl;
}

void constructTower_rec(list<Person>& ppl, stack<Person*>& tower, stack<Person*>& max_tower, size_t& max_ht, size_t level)
{
	if(level == ppl.size())
	{
		if(max_ht != level)
			max_tower = tower;
		max_ht = ppl.size();
		return;
	}

	bool atLeastOneAdded = false;

	for(list<Person>::iterator i = ppl.begin(); i != ppl.end(); ++i)
	{
		if(tower.empty() || isValid(*tower.top(), *i))
		{
			tower.push(&*i);
			i->setAvailability(false);

			constructTower_rec(ppl, tower, max_tower, max_ht, level + 1);
			i->setAvailability(true);
			tower.pop();
			atLeastOneAdded = true;
		}
	}

	if(!atLeastOneAdded)
	{
		if(max_ht < tower.size())
		{
			max_tower = tower;
			max_ht = tower.size();
		}
	}
}

bool isValid(Person& p1, Person& p2)
{
	return p1.height() > p2.height() && p1.weight() > p2.weight() && p2.isAvailable();
}

