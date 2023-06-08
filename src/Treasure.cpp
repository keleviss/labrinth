#include "Treasure.h"

Treasure::Treasure(WINDOW* win, Location* loc) : Movement(win, loc)
{
	character = '$';
}

Treasure::Treasure(const Treasure& tr) : Movement(tr.curwin, tr.location)
{

}

void Treasure::display()
{
	init_color(COLOR_WHITE, 0, 899, 0);
	char tmp = mvwinch(curwin, location->y, location->x);
	if (tmp != '&' && tmp != '%')
	{
		init_pair(6, COLOR_WHITE, COLOR_BLACK);
		mvwaddch(curwin, location->y, location->x, character | COLOR_PAIR(6));
	}
}