/*
 * Box.cpp
 *
 *  Created on: Feb 14, 2012
 *      Author: danielcumberbatch
 */

#include "Box.h"
#include <vector>
#include <iostream>

using std::vector;
using std::ostream;
using std::endl;
using std::cout;

bool operator<(const Box& b1, const Box& b2)
{
	return (b1.width() < b2.width()) && (b1.height() < b2.height()) && (b1.depth() < b2.depth());
}

bool Box::isBoxAvailable(const std::vector<Box>& b, const std::vector<Box>& curr_stack)
{
	if(curr_stack.empty())
		return true;
	Box top = curr_stack.back();
	for(vector<Box>::size_type i = 0; i != b.size(); ++i)
		if(!b[i].used() && b[i] < top)
			return true;
	return false;
}

vector<Box> Box::maxStack(vector<Box>& b)
{
	vector<Box> curr_stack, max_stack;
	return rec(b, curr_stack, max_stack);
}

vector<Box> Box::rec(vector<Box>& b, const vector<Box>& curr_stack, vector<Box>& max_stack)
{
	if(!isBoxAvailable(b, curr_stack))
	{
		//cout << "Next Iteration: " << endl;
		//display(cout, curr_stack);
		return curr_stack;
	}

	for(vector<Box>::size_type i = 0; i != b.size(); ++i)
	{
		if(!b[i].used() && (curr_stack.empty() || b[i] < curr_stack.back()))
		{
			vector<Box> tmp = curr_stack;
			b[i].setUsed(true);
			tmp.push_back(b[i]);
			tmp = rec(b, tmp, max_stack);
			if(tmp.size() > max_stack.size())
				max_stack = tmp;
			b[i].setUsed(false);
		}
	}
	return max_stack;
}

ostream& operator<<(ostream& os, const Box& b)
{
	os << b.width() << "\t" << b.height() << "\t" << b.depth();
	return os;
}

void Box::display(ostream& os, const vector<Box>& b)
{
	for(vector<Box>::const_reverse_iterator i = b.rbegin(); i != b.rend(); ++i)
			os << *i << endl;
	os << endl;
}
