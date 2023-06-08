#pragma once
#ifndef MOVING_H
#define MOVING_H
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

#include <string>
#include <curses.h>
#include <vector>
#include "Location.h"

class Movement
{
protected:
	WINDOW* curwin;
	int direction;
	char nextpos;
	chtype character;

public:
	std::vector<Location*> path;
	Location* location;
	Location* nextmove;

	Movement(WINDOW*, Location*);
	Movement(const Movement&);

	int getDir();
	void changeDir(int);

	bool checkup();
	bool checkdown();
	bool checkleft();
	bool checkright();
	bool checkupright();
	bool checkupleft();
	bool checkdownright();
	bool checkdownleft();

	void mvup();
	void mvdown();
	void mvleft();
	void mvright();
	int getmv();
	void followPath();

	void setyLoc(int);
	void setxLoc(int);

	int getyLoc();
	int getxLoc();
	char getChar();

	virtual void display();
};

#endif