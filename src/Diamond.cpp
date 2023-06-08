#include "Diamond.h"

Diamond::Diamond(WINDOW* win, Location* loc) : Movement(win, loc)
{
	character = ACS_DIAMOND;
}

Diamond::Diamond(const Diamond& tr) : Movement(tr.curwin, tr.location)
{
	character = ACS_DIAMOND;
}

void Diamond::Reset()
{
	character = ACS_DIAMOND;
}

void Diamond::display()
{
	init_color(COLOR_CYAN, 0, 655, 655);
	char tmp = mvwinch(curwin, location->y, location->x);
	if (tmp == '@')
	{
		character = ' ';
	}
	else if (tmp != 'i' && tmp != '}')
	{
		init_pair(7, COLOR_CYAN, COLOR_BLACK);
		mvwaddch(curwin, location->y, location->x, character | COLOR_PAIR(7));
	}
}
