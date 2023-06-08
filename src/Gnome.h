#pragma once
#ifndef GNOME_H
#define GNOME_H

#include <string>
#include <curses.h>
#include "Movement.h"

class Gnome : public Movement
{
public:
	Gnome(WINDOW*, Location*);
	Gnome(const Gnome&);

	char getChar();
	void display();
};

#endif