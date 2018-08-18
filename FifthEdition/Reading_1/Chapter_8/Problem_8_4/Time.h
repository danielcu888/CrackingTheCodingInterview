/*
 * Time.h
 *
 *  Created on: Mar 7, 2012
 *      Author: danielcumberbatch
 */

#ifndef TIME_H_
#define TIME_H_

#include <stdexcept>

class Time
{
public:
	Time(unsigned int hr_ = 0, unsigned int min_ = 0, unsigned int sec_ = 0)
		:	hr(hr_), min(min_), sec(sec_)
	{
		if(hr_ > 23 || min_ > 59 || sec > 59)
			throw std::out_of_range("invalid time!");
	}

private:
	unsigned int hr, min, sec;
};

#endif /* TIME_H_ */
