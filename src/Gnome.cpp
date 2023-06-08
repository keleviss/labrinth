#include "Gnome.h"

Gnome::Gnome(WINDOW* win, Location* loc) : Movement(win, loc)
{
	character = ACS_LANTERN;
}

Gnome::Gnome(const Gnome& g) : Movement(g.curwin, g.location)
{
	character = ACS_LANTERN;
}

char Gnome::getChar()
{
	return character;
}

void Gnome::display()
{
	init_color(COLOR_YELLOW, 750, 750, 0);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	mvwaddch(curwin, location->y, location->x, ACS_LANTERN | COLOR_PAIR(3));
}
