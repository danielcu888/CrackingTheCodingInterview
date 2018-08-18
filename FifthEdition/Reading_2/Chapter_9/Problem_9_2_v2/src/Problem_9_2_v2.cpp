//============================================================================
// Name        : Problem_9_2_v2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include "Point.h"
#include <cstddef>
#include <list>

using std::map;
using std::size_t; using std::list;

bool getPath(size_t, size_t, list<Point>&, const list<Point>&, map<Point, bool, bool(*)(Point, Point)>&);
bool isFree(size_t, size_t, const list<Point>&);

int main()
{
	return 0;
}

bool getPath(size_t x, size_t y, list<Point>& path, const list<Point>& hot_spots, map<Point, bool, bool(*)(Point, Point)>& cache)
{
	Point p(x,y);
	if(cache.find(p) != cache.end())
		return cache[p];
	path.push_back(p);
	bool success = false;
	if(x >= 1 && isFree(x - 1, y, hot_spots))
		success = getPath(x-1,y,path,hot_spots,cache);
	if(!success && y >= 1 && isFree(x, y - 1, hot_spots))
		success = getPath(x, y - 1, path, hot_spots, cache);
	if(!success)
		path.pop_back();
	cache[p] = success;
	return success;
}

bool isFree(size_t x, size_t y, const list<Point>& hot_spots)
{
	for(list<Point>::const_iterator iter = hot_spots.begin();
		iter != hot_spots.end(); ++iter)
		if(iter->getX() == x && iter->getY() == y)
			return false;
	return true;
}
