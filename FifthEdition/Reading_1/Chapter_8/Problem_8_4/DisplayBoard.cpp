/*
 * DisplayBoard.cpp
 *
 *  Created on: Mar 7, 2012
 *      Author: danielcumberbatch
 */

#include "DisplayBoard.h"
#include <vector>
#include <cstddef>
#include <sstream>
#include "Space.h"

using std::vector; using std::size_t;
using std::stringstream;

vector<size_t> DisplayBoard::getAvailableSpaces() const
{
	vector<size_t> ret(spaces.size());
	for(vector<vector<Space*> >::size_type i = 0; i != spaces.size(); ++i)
	{
		size_t count = 0;
		for(vector<Space*>::size_type j = 0; j != spaces[i].size(); ++j)
			if(spaces[i][j]->isAvailable()) ++count;
		ret[i] = count;
	}
	return ret;
}

void DisplayBoard::updateDisplay()
{
	static const std::string msg0 = "Level ";
	static const std::string msg1 = " spaces available";
	static const std::string msg2 = "No spaces available";

	vector<size_t> tmp = getAvailableSpaces();
	for(vector<size_t>::size_type i = 0; i != tmp.size(); ++i)
	{	stringstream ss;
		ss << msg0;
		ss << i;
		ss << ": ";
		if(tmp[i] == 0)
			ss << msg2;
		else
		{
			ss << tmp[i];
			ss << msg1;
		}
		displayboard[i] = ss.str();
	}
}


