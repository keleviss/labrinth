#pragma once
#ifndef TRAAL_H
#define TRAAL_H

#include <string>
#include <curses.h>
#include "Movement.h"

class Traal : public Movement
{
public:
	Traal(WINDOW*, Location*);
	Traal(const Traal&);

	char getChar();
	void display();
};

#endif