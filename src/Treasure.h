#pragma once
#ifndef TREASURE_H
#define TREASURE_H

#include <curses.h>
#include "Movement.h"

class Treasure : public Movement
{
public:
	Treasure(WINDOW*, Location*);
	Treasure(const Treasure&);
	void display();
};

#endif