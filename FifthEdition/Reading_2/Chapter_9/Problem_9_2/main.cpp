/*
 * main.cpp
 *
 *  Created on: Mar 27, 2012
 *      Author: danielcumberbatch
 */

#include "Point.h"
#include <vector>

using std::vector;

bool isFree(int x, int y, const vector<Point>& hot_spots)
{
	for(vector<Point>::const_iterator iter = hot_spots.begin();
		iter != hot_spots.end(); ++iter)
			if(iter->getX() == x && iter->getY() == y) return false;
	return true;
}

bool getPath(int x, int y, vector<Point>& path, const vector<Point>& hot_spots)
{
	Point p(x,y);
	path.push_back(p);
	if(x == 0 && y == 0)
		return true;
	bool success = false;
	if(x >= 1 && isFree(x - 1, y, hot_spots))
		success = getPath(x-1, y, path, hot_spots);
	if(!success && y >= 1 && isFree(x, y-1, hot_spots))
		success = getPath(x, y-1, path, hot_spots);
	if(!success)
		path.pop_back();
	return success;
}

int main()
{
	return 0;
}
