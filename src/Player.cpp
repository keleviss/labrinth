#include "Player.h"

Player::Player(WINDOW* win, Location* loc) : Movement(win, loc)
{
	character = '@';
}

Player::Player(const Player& p) : Movement(p.curwin, p.location)
{
	character = '@';
}

char Player::getChar()
{
	return character;
}

void Player::display()
{
	init_pair(5, COLOR_RED, COLOR_BLACK);
	mvwaddch(curwin, location->y, location->x, character | COLOR_PAIR(5));
}