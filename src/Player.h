#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <curses.h>
#include "Movement.h"

class Player : public Movement
{
public:
	Player(WINDOW*, Location*);
	Player(const Player&);

	char getChar();
	void display();
};

#endif