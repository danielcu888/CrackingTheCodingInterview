/*
 * DisplayBoard.h
 *
 *  Created on: Mar 7, 2012
 *      Author: danielcumberbatch
 */

#ifndef DISPLAYBOARD_H_
#define DISPLAYBOARD_H_

#include "Space.h"
#include <vector>
#include <string>
#include <cstddef>

class DisplayBoard
{
public:
	DisplayBoard(const std::vector<std::vector<Space*> >& _spaces)
		: spaces(_spaces), displayboard(_spaces.size())
		{}

	void updateDisplay();

private:
	std::vector<std::size_t> getAvailableSpaces() const;

	const std::vector<std::vector<Space*> >& spaces;
	std::size_t num_levels;

	std::vector<std::string> displayboard;
};

#endif /* DISPLAYBOARD_H_ */
