#pragma once
#ifndef DIAMOND_H
#define DIAMOND_H

#include <curses.h>
#include "Movement.h"

class Diamond : public Movement
{
public:
	Diamond(WINDOW*, Location*);
	Diamond(const Diamond&);

	void Reset();
	void display();
};

#endif