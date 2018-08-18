/*
 * Box.h
 *
 *  Created on: Feb 14, 2012
 *      Author: danielcumberbatch
 */

#ifndef BOX_H_
#define BOX_H_

#include <vector>
#include <iostream>

class Box
{
public:
	Box(double _wd = 0, double _ht = 0, double _dp = 0)
		: u(false), wd(_wd), ht(_ht), dp(_dp)
	{
		if(wd < 0) wd = 0;
		if(ht < 0) ht = 0;
		if(dp < 0) dp = 0;
	}

	double width() const {return wd;}
	double height() const {return ht;}
	double depth() const {return dp;}
	double used() const {return u;}

	void setWidth(double _wd) {wd = (_wd >= 0) ? _wd : wd;}
	void setHeight(double _ht) {ht = (_ht >= 0) ? _ht : ht;}
	void setDepth(double _dp) {dp = (_dp >= 0) ? _dp : dp;}
	void setUsed(bool _u) {u = _u;}

	static std::vector<Box> maxStack(std::vector<Box>&);
	static void display(std::ostream&, const std::vector<Box>&);

private:
	bool u;
	double wd, ht, dp;
	static bool isBoxAvailable(const std::vector<Box>&, const std::vector<Box>&);
	static std::vector<Box> rec(std::vector<Box>&, const std::vector<Box>&, std::vector<Box>&);
};

bool operator<(const Box&, const Box&);
std::ostream& operator<<(std::ostream&, const Box&);

#endif /* BOX_H_ */
