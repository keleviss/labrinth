#pragma once
#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <curses.h>
#include <string>
#include <vector>

class HighScore
{
private:
	std::vector <unsigned short int> scores;
	std::vector <std::string> names;
	int size;

public:
	HighScore();
	HighScore(std::vector <unsigned short int> sc, std::vector <std::string> ns);
	HighScore(const HighScore&);
	~HighScore();
	void setNewScore(unsigned short int, int);
	void setNewName(std::string, int);
	unsigned short int getScore(int);
	std::string getName(int);
	int getSize();
	bool empty();
};

#endif