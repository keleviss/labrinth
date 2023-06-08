#include "Movement.h"

Movement::Movement(WINDOW* win, Location* loc): curwin(win), location(loc)
{
	direction = 0;
	nextpos = 0;
}

Movement::Movement(const Movement& m) : curwin(m.curwin), location(m.location), direction(m.direction), nextpos(m.nextpos)
{

}

int Movement::getDir()
{
	return direction;
}

void Movement::changeDir(int dir)
{
	direction = dir;
}

bool Movement::checkup()
{
	if (direction == 0 || direction == LEFT || direction == UP || direction == RIGHT)
	{
		nextpos = mvwinch(curwin, location->y - 1, location->x);
		if (nextpos != 'a')
		{
			if (nextpos != '@')
			{
				if (nextpos == 'i' || nextpos == '}')
				{
					if (getDir() == UP)
						changeDir(DOWN);
					else if (getDir() == LEFT)
						changeDir(RIGHT);
					else if (getDir() == RIGHT)
						changeDir(LEFT);
					return false;
				}
			}
			else if (nextpos == '@')
				return true;
			for (int i = 2; i < 7; i++)
			{
				nextpos = mvwinch(curwin, location->y - i, location->x);
				if (nextpos != 'a')
				{
					if (nextpos != '@')
					{
						if (nextpos == 'i' || nextpos == '}')
						{
							if (getDir() == UP)
								changeDir(DOWN);
							else if (getDir() == LEFT)
								changeDir(RIGHT);
							else if (getDir() == RIGHT)
								changeDir(LEFT);
							return false;
						}
					}
					else if (nextpos == '@')
						return true;
				}
				else if (nextpos == 'a')
					break;
			}
			return true;
		}
		else if (nextpos == 'a')
			return false;
	}
	return false;
}

bool Movement::checkdown()
{
	if (direction == 0 || direction == LEFT || direction == DOWN || direction == RIGHT)
	{
		nextpos = mvwinch(curwin, location->y + 1, location->x);
		if (nextpos != 'a')
		{
			if (nextpos != '@')
			{
				if (nextpos == 'i' || nextpos == '}')
				{
					if (getDir() == DOWN)
						changeDir(UP);
					else if (getDir() == LEFT)
						changeDir(RIGHT);
					else if (getDir() == RIGHT)
						changeDir(LEFT);
					return false;
				}
			}
			else if (nextpos == '@')
				return true;
			for (int i = 2; i < 7; i++)
			{
				nextpos = mvwinch(curwin, location->y + i, location->x);
				if (nextpos != 'a')
				{
					if (nextpos != '@')
					{
						if (nextpos == 'i' || nextpos == '}')
						{
							if (getDir() == DOWN)
								changeDir(UP);
							else if (getDir() == LEFT)
								changeDir(RIGHT);
							else if (getDir() == RIGHT)
								changeDir(LEFT);
							return false;
						}
					}
					else if (nextpos == '@')
						return true;
				}
				else if (nextpos == 'a')
					break;
			}
			return true;
		}
		else if (nextpos == 'a')
			return false;
	}
	return false;
}

bool Movement::checkleft()
{
	if (direction == 0 || direction == LEFT || direction == UP || direction == DOWN)
	{
		nextpos = mvwinch(curwin, location->y, location->x - 1);
		if (nextpos != 'a')
		{
			if (nextpos != '@')
			{
				if (nextpos == 'i' || nextpos == '}')
				{
					if (getDir() == LEFT)
						changeDir(RIGHT);
					else if (getDir() == UP)
						changeDir(DOWN);
					else if (getDir() == DOWN)
						changeDir(UP);
					return false;
				}
			}
			else if (nextpos == '@')
				return true;

			for (int i = 2; i < 7; i++)
			{
				nextpos = mvwinch(curwin, location->y, location->x - i);
				if (nextpos != 'a')
				{
					if (nextpos != '@')
					{
						if (nextpos == 'i' || nextpos == '}')
						{
							if (getDir() == LEFT)
								changeDir(RIGHT);
							else if (getDir() == UP)
								changeDir(DOWN);
							else if (getDir() == DOWN)
								changeDir(UP);
							return false;
						}
					}
					else if (nextpos == '@')
						return true;
				}
				else if (nextpos == 'a')
					break;
			}
			return true;
		}
		else if (nextpos == 'a')
			return false;
	}
	return false;
}

bool Movement::checkright()
{
	if (direction == 0 || direction == UP || direction == DOWN || direction == RIGHT)
	{
		nextpos = mvwinch(curwin, location->y, location->x + 1);
		if (nextpos != 'a')
		{
			if (nextpos != '@')
			{
				if (nextpos == 'i' || nextpos == '}')
				{
					if (getDir() == RIGHT)
						changeDir(LEFT);
					else if (getDir() == UP)
						changeDir(DOWN);
					else if (getDir() == DOWN)
						changeDir(UP);
					return false;
				}
			}
			else if (nextpos == '@')
				return true;

			for (int i = 2; i < 7; i++)
			{
				nextpos = mvwinch(curwin, location->y, location->x + i);
				if (nextpos != 'a')
				{
					if (nextpos != '@')
					{
						if (nextpos == 'i' || nextpos == '}')
						{
							if (getDir() == RIGHT)
								changeDir(LEFT);
							else if (getDir() == UP)
								changeDir(DOWN);
							else if (getDir() == DOWN)
								changeDir(UP);
							return false;
						}
					}
					else if (nextpos == '@')
						return true;
				}
				else if (nextpos == 'a')
					break;
			}
			return true;
		}
		else if (nextpos == 'a')
			return false;
	}
	return false;
}

bool Movement::checkupright()
{
	nextpos = mvwinch(curwin, location->y - 1, location->x + 1);
	if (nextpos != 'a')
		return true;
	else
		return false;
}

bool Movement::checkupleft()
{
	nextpos = mvwinch(curwin, location->y - 1, location->x - 1);
	if (nextpos != 'a')
		return true;
	else
		return false;
}

bool Movement::checkdownright()
{
	nextpos = mvwinch(curwin, location->y + 1, location->x + 1);
	if (nextpos != 'a')
		return true;
	else
		return false;
}

bool Movement::checkdownleft()
{
	nextpos = mvwinch(curwin, location->y + 1, location->x - 1);
	if (nextpos != 'a')
		return true;
	else
		return false;
}

void Movement::mvup()
{
	nextpos = mvwinch(curwin, location->y - 1, location->x);
	if (nextpos != 'a')
	{
		direction = UP;
		mvwaddch(curwin, location->y, location->x, ' ');
		location->y--;
	}
}

void Movement::mvdown()
{
	nextpos = mvwinch(curwin, location->y + 1, location->x);
	if (nextpos != 'a')
	{
		direction = DOWN;
		mvwaddch(curwin, location->y, location->x, ' ');
		location->y++;
	}
}

void Movement::mvleft()
{
	nextpos = mvwinch(curwin, location->y, location->x - 1);
	if (nextpos != 'a')
	{
		direction = LEFT;
		mvwaddch(curwin, location->y, location->x, ' ');
		location->x--;
	}
}

void Movement::mvright()
{
	nextpos = mvwinch(curwin, location->y, location->x + 1);
	if (nextpos != 'a')
	{
		direction = RIGHT;
		mvwaddch(curwin, location->y, location->x, ' ');
		location->x++;
	}
}

int Movement::getmv()
{
	int choice = wgetch(curwin);
	switch (choice)
	{
	case KEY_UP:
		mvup();
		break;
	case KEY_DOWN:
		mvdown();
		break;
	case KEY_LEFT:
		mvleft();
		break;
	case KEY_RIGHT:
		mvright();
		break;
	case 27:
		break;
	}
	return choice;
}

void Movement::setyLoc(int y)
{
	location->y = y;
}

void Movement::setxLoc(int x)
{
	location->x = x;
}

int Movement::getyLoc()
{
	return location->y;
}

int Movement::getxLoc()
{
	return location->x;
}

char Movement::getChar()
{
	return character;
}

void Movement::display()
{
	mvwaddch(curwin, location->y, location->x, ' ');
}

void Movement::followPath()
{
	nextmove = path[1];
	location->y = nextmove->y;
	location->x = nextmove->x;
}