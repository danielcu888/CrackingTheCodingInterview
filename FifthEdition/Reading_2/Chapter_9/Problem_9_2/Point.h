/*
 * Point.h
 *
 *  Created on: Mar 27, 2012
 *      Author: danielcumberbatch
 */

#ifndef POINT_H_
#define POINT_H_

#include <cstddef>

class Point
{
public:
	Point(std::size_t x_ = 0, std::size_t y_ = 0)
		: x(x_), y(y_)
	{}

	std::size_t getX() const {return x;}
	std::size_t getY() const {return y;}

private:
	std::size_t x, y;
};

bool comparePoints(const Point& lhs, const Point& rhs)
{
	return lhs.getX() < rhs.getX() && lhs.getY() < rhs.getY();
}


#endif /* POINT_H_ */
