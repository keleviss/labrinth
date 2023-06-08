#include "Traal.h"

Traal::Traal(WINDOW* win, Location* loc) : Movement(win, loc)
{
	character = ACS_STERLING;
}

Traal::Traal(const Traal& t) : Movement(t.curwin, t.location)
{
	character = ACS_STERLING;
}

char Traal::getChar()
{
	return character;
}

void Traal::display()
{
	init_color(COLOR_MAGENTA, 600, 0, 999);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	mvwaddch(curwin, location->y, location->x, ACS_STERLING | COLOR_PAIR(4));
}
