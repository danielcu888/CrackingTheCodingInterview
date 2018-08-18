/*
 * findElement.cpp
 *
 *  Created on: Mar 12, 2012
 *      Author: danielcumberbatch
 */

#include "findElement.h"
#include <vector>

using std::vector;

bool findElement(const vector<vector<int> >& matrix, int val)
{
	size_t col = matrix[0].size() - 1;
	size_t row = 0;

	while(col >= 0 && row < matrix.size())
	{
		if(matrix[row][col] == val)
			return true;
		else if(matrix[row][col] > val)
			--col;
		else
			++row;
	}
	return false;
}


