#include "Engine.h"

/* Constructors */
Engine::Engine()
{
	menuoption = 0;
	gamesession = 0;
	score = 0;
	Setup();
}

Engine::Engine(int start)
{
	menuoption = 0;
	gamesession = 0;
	score = 0;
	Setup();
}

/* Destructor */
Engine::~Engine()
{
	Shutdown();
}

/* Engine Setup Function   *
 * Sets up the curses mode */
void Engine::Setup()
{
	initscr();
	noecho();
	cbreak();
	start_color();
	InitHighScores();
}

/* Curses Shutdown Function */
void Engine::Shutdown()
{
	delwin(gamewin);
	endwin();
}

/* Set up the Main Menu Screen */
int Engine::InitMenu()
{
	cbreak();

	if (gamewin == NULL)
	{
		resize_term(29, 95);
		gamewin = newwin(29, 95, 0, 0);
		curs_set(0);
		keypad(gamewin, TRUE);

		init_color(COLOR_GREEN, 734, 432, 123);
		init_pair(1, COLOR_GREEN, COLOR_BLACK);
	}
	wattron(gamewin, COLOR_PAIR(1));
	box(gamewin, 0, 0);

	std::string choices[4] = { "Play", "Top Scores", "Info", "Quit" };
	int choice;
	char chtmp;

	mvwprintw(gamewin, 2, (COLS / 2) - 43, "NN           NNNNNN   NNNNNNNN   NNNNNNNN   NNNNNNNNNN NNNN    NN NNNNNNNNNN NN      NN");
	mvwprintw(gamewin, 3, (COLS / 2) - 43, "NN         NN      NN NN      NN NN      NN     NN     NN NN   NN     NN     NN      NN");
	mvwprintw(gamewin, 4, (COLS / 2) - 43, "NN         NNNNNNNNNN NNNNNNNN   NNNNNNNN       NN     NN  NN  NN     NN     NNNNNNNNNN");
	mvwprintw(gamewin, 5, (COLS / 2) - 43, "NN         NN      NN NN      NN NN      NN     NN     NN   NN NN     NN     NN      NN");
	mvwprintw(gamewin, 6, (COLS / 2) - 43, "NNNNNNNNNN NN      NN NNNNNNNN   NN      NN NNNNNNNNNN NN    NNNN     NN     NN      NN");
	for (int i = (COLS / 2) - 43; i < (COLS / 2) + 44; i++)
		mvwaddch(gamewin, 8, i, ACS_HLINE);

	for (int i = 2; i < 7; i++)
	{
		for (int j = 3; j < 93; j++)
		{
			chtmp = mvwinch(gamewin, i, j);
			if (chtmp == 'N')
				mvwaddch(gamewin, i, j, ACS_CKBOARD);
		}
	}

	mvwprintw(gamewin, LINES - 2, COLS - 27, "Version 2.1 (June 25 2021)");
	mvwprintw(gamewin, LINES - 2, 1, "(Use the Arrow Keys to navigate)");

	while (1)
	{
		for (int i = 0; i < 4; i++)
		{
			if (choices[i] == "Play")
				mvwprintw(gamewin, i + 15, (COLS / 2) - 2, choices[i].c_str());
			if (choices[i] == "Top Scores")
				mvwprintw(gamewin, i + 16, (COLS / 2) - 5, choices[i].c_str());
			if (choices[i] == "Info")
				mvwprintw(gamewin, i + 17, (COLS / 2) - 2, choices[i].c_str());
			if (choices[i] == "Quit")
				mvwprintw(gamewin, i + 18, (COLS / 2) - 2, choices[i].c_str());
		}

		if (menuoption == 0)
		{
			mvwaddch(gamewin, menuoption + 15, (COLS / 2) - 4, ACS_RARROW);
			mvwaddch(gamewin, menuoption + 15, (COLS / 2) + 3, ACS_LARROW);
		}
		if (menuoption == 1)
		{
			mvwaddch(gamewin, menuoption + 16, (COLS / 2) - 7, ACS_RARROW);
			mvwaddch(gamewin, menuoption + 16, (COLS / 2) + 6, ACS_LARROW);
		}
		if (menuoption == 2)
		{
			mvwaddch(gamewin, menuoption + 17, (COLS / 2) - 4, ACS_RARROW);
			mvwaddch(gamewin, menuoption + 17, (COLS / 2) + 3, ACS_LARROW);
		}
		if (menuoption == 3)
		{
			mvwaddch(gamewin, menuoption + 18, (COLS / 2) - 4, ACS_RARROW);
			mvwaddch(gamewin, menuoption + 18, (COLS / 2) + 3, ACS_LARROW);
		}
		
		choice = wgetch(gamewin);

		if (menuoption == 0)
		{
			mvwaddch(gamewin, menuoption + 15, (COLS / 2) - 4, ' ');
			mvwaddch(gamewin, menuoption + 15, (COLS / 2) + 3, ' ');
		}
		if (menuoption == 1)
		{
			mvwaddch(gamewin, menuoption + 16, (COLS / 2) - 7, ' ');
			mvwaddch(gamewin, menuoption + 16, (COLS / 2) + 6, ' ');
		}
		if (menuoption == 2)
		{
			mvwaddch(gamewin, menuoption + 17, (COLS / 2) - 4, ' ');
			mvwaddch(gamewin, menuoption + 17, (COLS / 2) + 3, ' ');
		}
		if (menuoption == 3)
		{
			mvwaddch(gamewin, menuoption + 18, (COLS / 2) - 4, ' ');
			mvwaddch(gamewin, menuoption + 18, (COLS / 2) + 3, ' ');
		}

		switch (choice)
		{
		case KEY_UP:
			menuoption--;
			if (menuoption == -1)
				menuoption = 0;
			mvwprintw(gamewin, LINES - 2, 1, "                                ");
			break;
		case KEY_DOWN:
			menuoption++;
			if (menuoption == 4)
				menuoption = 3;
			mvwprintw(gamewin, LINES - 2, 1, "                                ");
			break;
		}

		if (choice == 10)
			break;
	}

	mvwprintw(gamewin, LINES - 2, 1, "                                ");
	wattroff(gamewin, COLOR_PAIR(1));
	wrefresh(gamewin);

	return menuoption;
}


/* Get Main Menu choice and execute */
void Engine::ExecMenuChoice(int option)
{
	if (option == 0) /* Play Option */ 
	{
		int gm = GameMode();

		if (gm != 0)
		{
			/* load map from map_file.txt if not loaded yet */
			if (map.empty())
				LoadMap();

			wclear(gamewin);
			wattron(gamewin, COLOR_PAIR(1));
			box(gamewin, 0, 0);
			wrefresh(gamewin);

			/* print map on screen */
			DrawMap();

			if (gamesession == 0)
			{
				/* initialize game characters and objectives */
				InitGnome();
				InitGnome();
				InitTraal();
				InitTraal();
				InitPotter();
				InitDiamonds();
				InitTreasure();
			}
			else
			{
				setNewLoc(player);
				player->display();
				setNewLoc(treasure);
				for (int i = 0; i < traal.size(); i++)
				{
					setNewLoc(traal[i]);
					traal[i]->display();
				}
				for (int i = 0; i < gnomes.size(); i++)
				{
					setNewLoc(gnomes[i]);
					gnomes[i]->display();
				}
				for (int j = 0; j < diamonds.size(); j++)
				{
					diamonds[j]->Reset();
					setNewLoc(diamonds[j]);
					diamonds[j]->display();
				}
			}

			wrefresh(mapwin);
			Play(gm); /* enable playerand monster movement */

			EndGameScreen(); /* print win or lose message */

			wclear(mapwin);
			wclear(endgamewin);
			wrefresh(endgamewin);
			wrefresh(mapwin);

			cbreak();
			ShowTopScores();

			SaveHighScores(); /* save scoreboard to scores_file.bin */
			if (score != 0)
				score = 0;
			gamesession++;
		}
	}
	if (option == 1) /* Top Scores Option */
	{
		ShowTopScores();
	}
	if (option == 2) /* Scoreboard option */
	{
		Help();
	}
}

/* Load Scores from binary file score.bin */
void Engine::LoadHighScores()
{
	std::filesystem::path cwd = std::filesystem::current_path();
	std::filesystem::path filepath = cwd / "gamefiles/scores.bin";
	std::ifstream bfile(filepath.string(), std::ios::binary | std::ios::in);

	bool empty = bfile.peek() == std::ifstream::traits_type::eof();

	if(empty)
	{
		std::cout << "Could not open file for scores loading!\n";
	}
	else
	{
		unsigned short intmp;
		unsigned short size;
		char chtmp;
		std::string strtmp;

		bfile.read((char*)&size, sizeof(unsigned short));

		if (size != 0)
		{
			for (int i = 0; i < size; i++)
			{
				bfile.read((char*)&intmp, sizeof(unsigned short));
				highscores->setNewScore(intmp, i);
			}

			for (int i = 0; i < size; i++)
			{
				bfile.read((char*)&intmp, sizeof(unsigned short));
				for (int j = 0; j < intmp; j++)
				{
					bfile.read((char*)&chtmp, sizeof(char));
					strtmp.push_back(chtmp);
				}
				highscores->setNewName(strtmp, i);
				strtmp.clear();
			}
		}
		bfile.close();

		if (!bfile.good())
		{
			std::cout << "Something went wrong while reading." << std::endl;
		}
	}
}

/* Save Scores back to binary file scores.bin */
void Engine::SaveHighScores()
{
	unsigned short scoretmp;
	char chtmp;
	std::string strtmp;

	std::filesystem::path cwd = std::filesystem::current_path();
	std::filesystem::path filepath = cwd / "gamefiles/scores.bin";
	std::ofstream bfile(filepath.string(), std::ios::binary | std::ios::out);
	if (!bfile)
	{
		std::cout << "Could not open binary file." << std::endl;
	}
	else
	{
		scoretmp = highscores->getSize();

		bfile.write((char*)&scoretmp, sizeof(unsigned short));

		for (int i = 0; i < highscores->getSize(); i++)
		{
			scoretmp = highscores->getScore(i);
			bfile.write((char*)&scoretmp, sizeof(unsigned short));
		}

		for (int i = 0; i < highscores->getSize(); i++)
		{
			strtmp = highscores->getName(i);
			scoretmp = strtmp.length();

			bfile.write((char*)&scoretmp, sizeof(unsigned short));

			for (int j = 0; j < scoretmp; j++)
			{
				chtmp = strtmp.at(j);
				bfile.write((char*)&chtmp, sizeof(char));
			}
		}
		if (!bfile.good())
			std::cout << "Something went wrong while reading." << std::endl;
	}

	bfile.close();
}

/* Load Map from text file map_easy.txt */
void Engine::LoadMap()
{
	std::string tmp;

	std::filesystem::path cwd = std::filesystem::current_path();
	std::filesystem::path filepath = cwd / "gamefiles/map_hard.txt";

	std::ifstream mfile;
	mfile.open(filepath.string());
	if (!mfile)
	{
		std::cout << "Map File could not be opened." << std::endl;
		exit(1);
	}

	while (std::getline(mfile, tmp))
		map.push_back(tmp);
	
	int len = (map[0].length());
	
	mfile.close();
}

/* Draw Map on Curses Window */
void Engine::DrawMap()
{
	int height = map.size();
	int width = map[0].length();

	int starty = (LINES/2) - (height/2);
	int startx = (COLS / 2) - (width / 2);

	if (mapwin == NULL)
	{
		mapwin = newwin(height + 1, width, starty, startx);
		keypad(mapwin, true);
	}
	wattron(mapwin, COLOR_PAIR(1));

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i].at(j) == '*')
			{
				mvwaddch(mapwin, i, j, ACS_CKBOARD);
			}
			else
			{
				mvwaddch(mapwin, i, j, ' ');
			}
		}
	}
	
	mvwprintw(mapwin, map.size(), 0, "Score: %hu", score);
	wrefresh(gamewin);
	wattroff(gamewin, COLOR_PAIR(1));
}

/* Initializing Player in a random location */
void Engine::InitPotter()
{
	char tmp;
	int y, x;
	y = x = 0;

	srand(time(0));

	y = (rand() % (map.size() - 1));
	x = (rand() % map[0].length());
	tmp = mvwinch(mapwin, y, x);
	while (tmp != ' ')
	{
		y = (rand() % (map.size() - 1));
		x = (rand() % map[0].length());
		tmp = mvwinch(mapwin, y, x);
	}

	Location* loc = new Location(y, x);
	Player* p = new Player(mapwin, loc);
	player = p;
	player->display();
}

/* Initializing Traal in a random location */
void Engine::InitTraal()
{
	char tmp;
	int y, x;
	y = x = 0;

	srand(time(0));

	y = (rand() % (map.size() - 1));
	x = (rand() % map[0].length());
	tmp = mvwinch(mapwin, y, x);
	while (tmp != ' ')
	{
		y = (rand() % (map.size() - 1));
		x = (rand() % map[0].length());
		tmp = mvwinch(mapwin, y, x);
	}

	Location* loc = new Location(y, x);
	Traal* t = new Traal(mapwin, loc);
	traal.push_back(t);
	traal.back()->display();
}

/* Initializing Gnome in a random location */
void Engine::InitGnome()
{
	char tmp;
	int y, x;
	y = x = 0;

	srand(time(0));

	y = (rand() % (map.size() - 1));
	x = (rand() % map[0].length());
	tmp = mvwinch(mapwin, y, x);
	while (tmp != ' ')
	{
		y = (rand() % (map.size() - 1));
		x = (rand() % map[0].length());
		tmp = mvwinch(mapwin, y, x);
	}

	Location* loc = new Location(y, x);
	Gnome* g = new Gnome(mapwin, loc);
	gnomes.push_back(g);
	gnomes.back()->display();
}

/* Initializing 10 Diamonds in 10 random locations */
void Engine::InitDiamonds()
{
	char tmp;
	int y, x;
	y = x = 0;

	srand(time(0));

	for (int i = 0; i < 10; i++)
	{
		y = (rand() % (map.size() - 1));
		x = (rand() % map[0].length());
		tmp = mvwinch(mapwin, y, x);
		while (tmp != ' ')
		{
			y = (rand() % (map.size() - 1));
			x = (rand() % map[0].length());
			tmp = mvwinch(mapwin, y, x);
		}
		Location* loc = new Location(y, x);
		Diamond* dmnd = new Diamond(mapwin, loc);
		diamonds.push_back(dmnd);
		diamonds.back()->display();
	}
}

/* Initializing Treasure in a random location */
void Engine::InitTreasure()
{
	char tmp;
	int y, x;
	y = x = 0;

	srand(time(0));

	y = (rand() % (map.size() - 1));
	x = (rand() % map[0].length());
	tmp = mvwinch(mapwin, y, x);
	while (tmp != ' ')
	{
		y = (rand() % (map.size() - 1));
		x = (rand() % map[0].length());
		tmp = mvwinch(mapwin, y, x);
	}

	Location* loc = new Location(y, x);
	Treasure* tres = new Treasure(mapwin, loc);
	treasure = tres;
}

/* Initializing session's HighScores */
void Engine::InitHighScores()
{
	highscores = new HighScore();
	LoadHighScores();
}

/* Checking for new high score, if there is *
 * a new high score, ask player for a name  *
 * and save new high score                  */
void Engine::NewHighScore(int height, int width, int starty, int startx)
{
	int newscore = 0;

	for (int i = 0; i < 5; i++)
	{
		if (score > highscores->getScore(i))
		{
			mvwprintw(scoreswin, 3, (width / 2) - 8, "!NEW HIGH SCORE!");
			mvwprintw(scoreswin, 6, (width / 2) - 7, "Enter Nickname:");
			if(namewin == NULL)
				namewin = newwin(3, 12, starty + (height / 2), startx + (width / 2) - 6);
			wattron(namewin, COLOR_PAIR(1));
			box(namewin, 0, 0);
			wrefresh(scoreswin);
			wrefresh(namewin);

			curs_set(1);
			char ch;
			int flag = 0;
			int cursor = 1;
			while (1)
			{
				ch = mvwgetch(namewin, 1, cursor);
				switch(ch)
				{
				case '\n':
					break;
				case 27:
					break;
				case 8:
					if (cursor == 10 && flag == 1)
					{
						enter_name.pop_back();
						mvwaddch(namewin, 1, cursor, ' ');
						flag = 0;
					}
					else
					{
						if(!enter_name.empty())
							enter_name.pop_back();
						cursor--;
						if (cursor < 1)
						{
							cursor = 1;
							mvwaddch(namewin, 1, cursor, ' ');
						}
						else {
							mvwaddch(namewin, 1, cursor , ' ');
						}
					}
				default:
					if (ch != 8)
					{
						mvwaddch(namewin, 1, cursor, ch);
						cursor++;
						if (cursor > 10)
						{
							enter_name.pop_back();
							cursor = 10;
							flag = 1;
							enter_name.push_back(ch);
						}
						else
							enter_name.push_back(ch);
					}
				}
				if (ch == '\n')
					break;
			}
			highscores->setNewScore(score, i);
			highscores->setNewName(enter_name, i);
			newscore++;
			SaveHighScores();
		}
		if (newscore == 1)
			break;
	}

	mvwprintw(scoreswin, 3, (width / 2) - 8, "                ");
	mvwprintw(scoreswin, 6, (width / 2) - 7, "               ");

	curs_set(0);
	wclear(namewin);
	wrefresh(namewin);
	wattroff(namewin, COLOR_PAIR(1));

	enter_name.clear();
}

/* Print the Score Board in a Curses Window */
void Engine::ShowTopScores()
{
	init_color(COLOR_WHITE, 999, 999, 999);

	char chtmp;
	wattron(gamewin, COLOR_PAIR(1));
	mvwprintw(gamewin, 2, (COLS / 2) - 43, "NN           NNNNNN   NNNNNNNN   NNNNNNNN   NNNNNNNNNN NNNN    NN NNNNNNNNNN NN      NN");
	mvwprintw(gamewin, 3, (COLS / 2) - 43, "NN         NN      NN NN      NN NN      NN     NN     NN NN   NN     NN     NN      NN");
	mvwprintw(gamewin, 4, (COLS / 2) - 43, "NN         NNNNNNNNNN NNNNNNNN   NNNNNNNN       NN     NN  NN  NN     NN     NNNNNNNNNN");
	mvwprintw(gamewin, 5, (COLS / 2) - 43, "NN         NN      NN NN      NN NN      NN     NN     NN   NN NN     NN     NN      NN");
	mvwprintw(gamewin, 6, (COLS / 2) - 43, "NNNNNNNNNN NN      NN NNNNNNNN   NN      NN NNNNNNNNNN NN    NNNN     NN     NN      NN");
	for (int i = (COLS / 2) - 43; i < (COLS / 2) + 44; i++)
		mvwaddch(gamewin, 8, i, ACS_HLINE);
	for (int i = 2; i < 7; i++)
	{
		for (int j = 3; j < 93; j++)
		{
			chtmp = mvwinch(gamewin, i, j);
			if (chtmp == 'N')
				mvwaddch(gamewin, i, j, ACS_CKBOARD);
		}
	}
	wrefresh(gamewin);
	wattroff(gamewin, COLOR_PAIR(1));

	int maxy, maxx;
	int y, x;
	if (scoreswin == NULL)
		scoreswin = newwin(17, 63, (LINES / 2) - 5, (COLS / 2) - 31);
	wattron(scoreswin, COLOR_PAIR(1));
	box(scoreswin, 0, 0);
	maxy = getmaxy(scoreswin);
	maxx = getmaxx(scoreswin);
	y = getbegy(scoreswin);
	x = getbegx(scoreswin);

	NewHighScore(maxy, maxx, y, x);

	mvwprintw(scoreswin, 2, (maxx / 2) - 8, "                ");
	mvwprintw(scoreswin, (maxy / 2) - 6, (maxx / 2) - 5, "TOP SCORES");
	mvwprintw(scoreswin, (maxy / 2) - 4, (maxx / 2) - 17, "RANK           SCORE           NAME");

	mvwprintw(scoreswin, (maxy / 2) - 2, (maxx / 2) - 17, "1ST");
	mvwprintw(scoreswin, (maxy / 2) - 0, (maxx / 2) - 17, "2ND");
	mvwprintw(scoreswin, (maxy / 2) + 2, (maxx / 2) - 17, "3RD");
	mvwprintw(scoreswin, (maxy / 2) + 4, (maxx / 2) - 17, "4TH");
	mvwprintw(scoreswin, (maxy / 2) + 6, (maxx / 2) - 17, "5TH");
	wrefresh(scoreswin);
	wattroff(scoreswin, COLOR_PAIR(1));

	for (int i = 0; i < 5; i++)
	{
		if(highscores->getScore(i) > 99)
			mvwprintw(scoreswin, (maxy / 2) - 2 + 2*i, (maxx / 2), "%d", highscores->getScore(i));
		else if(highscores->getScore(i) > 0)
			mvwprintw(scoreswin, (maxy / 2) - 2 + 2*i, (maxx / 2) + 1, "%d", highscores->getScore(i));
		else 
			mvwprintw(scoreswin, (maxy / 2) - 2 + 2*i, (maxx / 2) + 2, "%d", highscores->getScore(i));

		int length = highscores->getName(i).length();
		mvwprintw(scoreswin, ((maxy / 2) - 2 + 2*i), (maxx - 14 - length), "%s", highscores->getName(i).c_str());
	}
	
	wrefresh(scoreswin);



	getch();
	wclear(scoreswin);
	wrefresh(scoreswin);

}

/* Run game mode */
void Engine::Play(int mode)
{
	char chtmp;
	bool treasure_flag = false;
	int y, x;

	halfdelay(mode);

	while (score != 200)
	{
		char choice = player->getmv();
		y = player->getyLoc();
		x = player->getxLoc();
		chtmp = mvwinch(mapwin, y, x);
		
		if(choice == 27)
		{
			break;
		}	

		if (chtmp == '`')
			score += 10;
		else if (chtmp == '$')
		{
			score += 100;
			break;
		}

		player->display();
		
		if (score == 100 && treasure_flag == false)
			treasure_flag = true;
		if (treasure_flag == true)
			treasure->display();

		for (int i = 0; i < gnomes.size(); i++)
		{
			gnomeMv(gnomes[i], player);
			gnomes[i]->display();
		}

		for (int i = 0; i < traal.size(); i++)
		{
			traalMv(traal[i], player);
			traal[i]->display();
		}

		for (int j = 0; j < diamonds.size(); j++)
			diamonds[j]->display();

		y = player->getyLoc();
		x = player->getxLoc();
		chtmp = mvwinch(mapwin, y, x);

		if (chtmp == 'i' || chtmp == '}')
			break;
			
		wattron(mapwin, COLOR_PAIR(1));
		mvwprintw(mapwin, map.size(), 0, "Score: %hu", score);
		wrefresh(mapwin);
		wattroff(mapwin, COLOR_PAIR(1));
	}
	nocbreak();
}

/* End game screen considering the score */
void Engine::EndGameScreen()
{
	if (score == 200)
		GameWON();
	else
		GameOver();
}

/* Print Game Over animation on Game Screen */
void Engine::GameOver()
{
	int maxy, maxx;
	if (endgamewin == NULL)
	{
		endgamewin = newwin(9, 23, (LINES / 2) - 4, (COLS / 2) - 11);
	}

	maxy = getmaxy(endgamewin);
	maxx = getmaxx(endgamewin);

	wattron(endgamewin, COLOR_PAIR(1));
	box(endgamewin, 0, 0);
	mvwprintw(endgamewin, (maxy / 2), (maxx / 2) - 4, "GAME OVER");
	wrefresh(endgamewin);
	wattroff(endgamewin, COLOR_PAIR(1));

	int ch = getch();
	while (ch != '\n')
		ch = getch();
}

/* Print You Won animation on Game Screen */
void Engine::GameWON()
{
	int maxy, maxx;
	if (endgamewin == NULL)
	{
		endgamewin = newwin(9, 23, (LINES / 2) - 4, (COLS / 2) - 11);
	}

	maxy = getmaxy(endgamewin);
	maxx = getmaxx(endgamewin);

	wattron(endgamewin, COLOR_PAIR(1));
	box(endgamewin, 0, 0);
	mvwprintw(endgamewin, maxy / 2, (maxx / 2) - 4, "$YOU WON$");
	wrefresh(endgamewin);
	wattroff(endgamewin, COLOR_PAIR(1));

	int ch = getch();
	while (ch != '\n')
		ch = getch();
}

/* Help Menu Panel */
void Engine::Help()
{
	int maxy, maxx;
	if (helpwin == NULL)
		helpwin = newwin(17, 63, (LINES / 2) - 5, (COLS / 2) - 31);
	maxy = getmaxy(helpwin);
	maxx = getmaxx(helpwin);

	wattron(helpwin, COLOR_PAIR(1));
	box(helpwin, 0, 0);

	mvwprintw(helpwin, 1, 2, "Info");
	/*mvwaddch(helpwin, 2, 0, ACS_LTEE);
	mvwaddch(helpwin, 2, maxx - 1, ACS_RTEE);
	for (int i = 1; i < maxx - 1; i++)
		mvwaddch(helpwin, 2, i, ACS_HLINE);*/
	wattroff(helpwin, COLOR_PAIR(1));

	mvwprintw(helpwin, 3, 2, "Game inspired by 'PACMAN'. Designed and developed by");
	mvwprintw(helpwin, 4, 2, "Kelesidis Vissarion. Contact: kelesidisvissarion@gmail.com");
	wrefresh(helpwin);
	
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	wattron(helpwin, COLOR_PAIR(3));
	mvwprintw(helpwin, 4, 32, "kelesidisvissarion@gmail.com");
	wattroff(helpwin, COLOR_PAIR(3));
	wrefresh(helpwin);

	wattron(helpwin, COLOR_PAIR(1));
	mvwprintw(helpwin, 7, 2, "How to Play");
	wattroff(helpwin, COLOR_PAIR(1));
	mvwprintw(helpwin, 9, 2, "When in game, use the arrow keys to move your character ' '");
	mvwprintw(helpwin, 11, 2, "You need to gather all the Diamonds ' ' in order to reveal");
	mvwprintw(helpwin, 12, 2, "the Treasure ' '. Find the Treasure to win the game.");
	mvwprintw(helpwin, 14, 2, "Be careful there are wild Gnomes ' ' lurking and a big");
	mvwprintw(helpwin, 15, 2, "Traal ' '. Don't let them catch you.");

	wrefresh(helpwin);

	init_pair(2, COLOR_RED, COLOR_BLACK);
	mvwaddch(helpwin, 9, 59, '@' | COLOR_PAIR(2));
	init_color(COLOR_CYAN, 0, 655, 655);
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	mvwaddch(helpwin, 11, 39, ACS_DIAMOND | COLOR_PAIR(7));
	mvwaddch(helpwin, 12, 16, '$' | COLOR_PAIR(1));
	init_color(COLOR_YELLOW, 750, 750, 0);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	mvwaddch(helpwin, 14, 36, ACS_LANTERN | COLOR_PAIR(5));
	init_color(COLOR_MAGENTA, 600, 0, 999);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	mvwaddch(helpwin, 15, 9, ACS_STERLING | COLOR_PAIR(4));

	wrefresh(helpwin);

	getch();
	wclear(helpwin);
	wrefresh(helpwin);
}

/* Traal and Gnome movement AI */
void Engine::gnomeMv(Movement* m, Movement* target)
{
	int py, px;
	int cy, cx;
	int ydiff, xdiff;

	py = target->getyLoc();
	px = target->getxLoc();

	cy = m->getyLoc();
	cx = m->getxLoc();

	ydiff = py - cy;
	xdiff = px - cx;

	if (ydiff < 0 && xdiff < 0)
	{
		if (ydiff == xdiff)
		{
			if (m->checkleft())
				m->mvleft();
			else if (m->checkup())
				m->mvup();
			else if (m->getDir() == 2)
			{
				if (m->checkdown())
					m->mvdown();
				else if (m->checkright())
					m->mvright();
			}
			else if (m->getDir() == 4)
			{
				if (m->checkright())
					m->mvright();
				else if (m->checkdown())
					m->mvdown();
			}
			else
			{
				if (m->checkright())
					m->mvright();
				else if (m->checkdown())
					m->mvdown();
			}
		}
		else if (ydiff > xdiff)
		{
			if (m->checkleft())
				m->mvleft();
			else if (m->checkup())
				m->mvup();
			else if (m->getDir() == 2)
			{
				if (m->checkdown())
					m->mvdown();
				else if (m->checkright())
					m->mvright();
			}
			else if (m->getDir() == 4)
			{
				if (m->checkright())
					m->mvright();
				else if (m->checkdown())
					m->mvdown();
			}
			else
			{
				if (m->checkright())
					m->mvright();
				else if (m->checkdown())
					m->mvdown();
			}
		}
		else if (ydiff < xdiff)
		{
			if (m->checkup())
				m->mvup();
			else if (m->checkleft())
				m->mvleft();
			else if (m->getDir() == 2)
			{
				if (m->checkdown())
					m->mvdown();
				else if (m->checkright())
					m->mvright();
			}
			else if (m->getDir() == 4)
			{
				if (m->checkright())
					m->mvright();
				else if (m->checkdown())
					m->mvdown();
			}
			else
			{
				if (m->checkright())
					m->mvright();
				else if (m->checkdown())
					m->mvdown();
			}
		}
	}
	else if (ydiff < 0 && xdiff > 0)
	{
		if (abs(ydiff) == xdiff)
		{
			if (m->checkright())
				m->mvright();
			else if (m->checkup())
				m->mvup();
			else if (m->getDir() == 2)
			{
				if (m->checkdown())
					m->mvdown();
				else if (m->checkleft())
					m->mvleft();
			}
			else if (m->getDir() == 3)
			{
				if (m->checkleft())
					m->mvleft();
				else if (m->checkdown())
					m->mvdown();
			}
			else
			{
				if (m->checkleft())
					m->mvleft();
				else if (m->checkdown())
					m->mvdown();
			}
		}
		else if (abs(ydiff) < xdiff)
		{
			if (m->checkright())
				m->mvright();
			else if (m->checkup())
				m->mvup();
			else if (m->getDir() == 2)
			{
				if (m->checkdown())
					m->mvdown();
				else if (m->checkleft())
					m->mvleft();
			}
			else if (m->getDir() == 3)
			{
				if (m->checkleft())
					m->mvleft();
				else if (m->checkdown())
					m->mvdown();
			}
			else
			{
				if (m->checkleft())
					m->mvleft();
				else if (m->checkdown())
					m->mvdown();
			}
		}
		else if (abs(ydiff) > xdiff)
		{
			if (m->checkup())
				m->mvup();
			else if (m->checkright())
				m->mvright();
			else if (m->getDir() == 2)
			{
				if (m->checkdown())
					m->mvdown();
				else if (m->checkleft())
					m->mvleft();
			}
			else if (m->getDir() == 3)
			{
				if (m->checkleft())
					m->mvleft();
				else if (m->checkdown())
					m->mvdown();
			}
			else
			{
				if (m->checkleft())
					m->mvleft();
				else if (m->checkdown())
					m->mvdown();
			}
		}
	}
	else if (ydiff > 0 && xdiff > 0)
	{
		if (ydiff == xdiff)
		{
			if (m->checkright())
				m->mvright();
			else if (m->checkdown())
				m->mvdown();
			else if (m->getDir() == 1)
			{
				if (m->checkup())
					m->mvup();
				else if (m->checkleft())
					m->mvleft();
			}
			else if (m->getDir() == 3)
			{
				if (m->checkleft())
					m->mvleft();
				else if (m->checkup())
					m->mvup();
			}
			else
			{
				if (m->checkleft())
					m->mvleft();
				else if (m->checkup())
					m->mvup();
			}
		}
		else if (ydiff < xdiff)
		{
			if (m->checkright())
				m->mvright();
			else if (m->checkdown())
				m->mvdown();
			else if (m->getDir() == 1)
			{
				if (m->checkup())
					m->mvup();
				else if (m->checkleft())
					m->mvleft();
			}
			else if (m->getDir() == 3)
			{
				if (m->checkleft())
					m->mvleft();
				else if (m->checkup())
					m->mvup();
			}
			else
			{
				if (m->checkleft())
					m->mvleft();
				else if (m->checkup())
					m->mvup();
			}
		}
		else if (ydiff > xdiff)
		{
			if (m->checkdown())
				m->mvdown();
			else if (m->checkright())
				m->mvright();
			else if (m->getDir() == 1)
			{
				if (m->checkup())
					m->mvup();
				else if (m->checkleft())
					m->mvleft();
			}
			else if (m->getDir() == 3)
			{
				if (m->checkleft())
					m->mvleft();
				else if (m->checkup())
					m->mvup();
			}
			else
			{
				if (m->checkleft())
					m->mvleft();
				else if (m->checkup())
					m->mvup();
			}
		}
	}
	else if (ydiff > 0 && xdiff < 0)
	{
		if (ydiff == abs(xdiff))
		{
			if (m->checkleft())
				m->mvleft();
			else if (m->checkdown())
				m->mvdown();
			else if (m->getDir() == 1)
			{
				if (m->checkup())
					m->mvup();
				else if (m->checkright())
					m->mvright();
			}
			else if (m->getDir() == 4)
			{
				if (m->checkright())
					m->mvright();
				else if (m->checkup())
					m->mvup();
			}
			else
			{
				if (m->checkright())
					m->mvright();
				else if (m->checkup())
					m->mvup();
			}
		}
		else if (ydiff < abs(xdiff))
		{
			if (m->checkleft())
				m->mvleft();
			else if (m->checkdown())
				m->mvdown();
			else if (m->getDir() == 1)
			{
				if (m->checkup())
					m->mvup();
				else if (m->checkright())
					m->mvright();
			}
			else if (m->getDir() == 4)
			{
				if (m->checkright())
					m->mvright();
				else if (m->checkup())
					m->mvup();
			}
			else
			{
				if (m->checkright())
					m->mvright();
				else if (m->checkup())
					m->mvup();
			}
		}
		else if (ydiff > abs(xdiff))
		{
			if (m->checkdown())
				m->mvdown();
			else if (m->checkleft())
				m->mvleft();
			else if (m->getDir() == 1)
			{
				if (m->checkup())
					m->mvup();
				else if (m->checkright())
					m->mvright();
			}
			else if (m->getDir() == 4)
			{
				if (m->checkright())
					m->mvright();
				else if (m->checkup())
					m->mvup();
			}
			else
			{
				if (m->checkright())
					m->mvright();
				else if (m->checkup())
					m->mvup();
			}
		}
	}
	else if (ydiff == 0 && xdiff < 0)
	{
		if (m->checkleft())
			m->mvleft();
		else if (m->checkupleft() && m->checkup())
			m->mvup();
		else if (m->checkdownleft() && m->checkdown())
			m->mvdown();
		else if (m->checkup())
			m->mvup();
		else if (m->checkdown())
			m->mvdown();
		else if (m->checkright())
			m->mvright();
	}
	else if (ydiff == 0 && xdiff > 0)
	{
		if (m->checkright())
			m->mvright();
		else if (m->checkupright() && m->checkup())
			m->mvup();
		else if (m->checkdownright() && m->checkdown())
			m->mvdown();
		else if (m->checkup())
			m->mvup();
		else if (m->checkdown())
			m->mvdown();
		else if (m->checkleft())
			m->mvleft();
	}
	else if (ydiff < 0 && xdiff == 0)
	{
		if (m->checkup())
			m->mvup();
		else if (m->checkupleft() && m->checkleft())
			m->mvleft();
		else if (m->checkupright() && m->checkright())
			m->mvright();
		else if (m->checkleft())
			m->mvleft();
		else if (m->checkright())
			m->mvright();
		else if (m->checkdown())
			m->mvdown();
	}
	else if (ydiff > 0 && xdiff == 0)
	{
		if (m->checkdown())
			m->mvdown();
		else if (m->checkdownleft() && m->checkleft())
			m->mvleft();
		else if (m->checkdownright() && m->checkright())
			m->mvright();
		else if (m->checkleft())
			m->mvleft();
		else if (m->checkright())
			m->mvright();
		else if (m->checkup())
			m->mvup();
	}
}

void Engine::traalMv(Movement* m, Movement* target)
{
	int py, px;
	int cy, cx;
	int ydiff, xdiff;

	py = target->getyLoc();
	px = target->getxLoc();

	cy = m->getyLoc();
	cx = m->getxLoc();

	ydiff = py - cy;
	xdiff = px - cx;

	if (ydiff < 0 && xdiff < 0)
	{
		if (ydiff == xdiff)
		{
			if (m->checkleft())
				m->mvleft();
			else if (m->checkup())
				m->mvup();
			else if (m->getDir() == 2)
			{
				if (m->checkdown())
					m->mvdown();
				else if (m->checkright())
					m->mvright();
			}
			else if (m->getDir() == 4)
			{
				if (m->checkright())
					m->mvright();
				else if (m->checkdown())
					m->mvdown();
			}
			else
			{
				if (m->checkright())
					m->mvright();
				else if (m->checkdown())
					m->mvdown();
			}
		}
		else if (ydiff < xdiff)
		{
			if (m->checkleft())
				m->mvleft();
			else if (m->checkup())
				m->mvup();
			else if (m->getDir() == 2)
			{
				if (m->checkdown())
					m->mvdown();
				else if (m->checkright())
					m->mvright();
			}
			else if (m->getDir() == 4)
			{
				if (m->checkright())
					m->mvright();
				else if (m->checkdown())
					m->mvdown();
			}
			else
			{
				if (m->checkright())
					m->mvright();
				else if (m->checkdown())
					m->mvdown();
			}
		}
		else if (ydiff > xdiff)
		{
			if (m->checkup())
				m->mvup();
			else if (m->checkleft())
				m->mvleft();
			else if (m->getDir() == 2)
			{
				if (m->checkdown())
					m->mvdown();
				else if (m->checkright())
					m->mvright();
			}
			else if (m->getDir() == 4)
			{
				if (m->checkright())
					m->mvright();
				else if (m->checkdown())
					m->mvdown();
			}
			else
			{
				if (m->checkright())
					m->mvright();
				else if (m->checkdown())
					m->mvdown();
			}
		}
	}
	else if (ydiff < 0 && xdiff > 0)
	{
		if (abs(ydiff) == xdiff)
		{
			if (m->checkright())
				m->mvright();
			else if (m->checkup())
				m->mvup();
			else if (m->getDir() == 2)
			{
				if (m->checkdown())
					m->mvdown();
				else if (m->checkleft())
					m->mvleft();
			}
			else if (m->getDir() == 3)
			{
				if (m->checkleft())
					m->mvleft();
				else if (m->checkdown())
					m->mvdown();
			}
			else
			{
				if (m->checkleft())
					m->mvleft();
				else if (m->checkdown())
					m->mvdown();
			}
		}
		else if (abs(ydiff) > xdiff)
		{
			if (m->checkright())
				m->mvright();
			else if (m->checkup())
				m->mvup();
			else if (m->getDir() == 2)
			{
				if (m->checkdown())
					m->mvdown();
				else if (m->checkleft())
					m->mvleft();
			}
			else if (m->getDir() == 3)
			{
				if (m->checkleft())
					m->mvleft();
				else if (m->checkdown())
					m->mvdown();
			}
			else
			{
				if (m->checkleft())
					m->mvleft();
				else if (m->checkdown())
					m->mvdown();
			}
		}
		else if (abs(ydiff) < xdiff)
		{
			if (m->checkup())
				m->mvup();
			else if (m->checkright())
				m->mvright();
			else if (m->getDir() == 2)
			{
				if (m->checkdown())
					m->mvdown();
				else if (m->checkleft())
					m->mvleft();
			}
			else if (m->getDir() == 3)
			{
				if (m->checkleft())
					m->mvleft();
				else if (m->checkdown())
					m->mvdown();
			}
			else
			{
				if (m->checkleft())
					m->mvleft();
				else if (m->checkdown())
					m->mvdown();
			}
		}
	}
	else if (ydiff > 0 && xdiff > 0)
	{
		if (ydiff == xdiff)
		{
			if (m->checkright())
				m->mvright();
			else if (m->checkdown())
				m->mvdown();
			else if (m->getDir() == 1)
			{
				if (m->checkup())
					m->mvup();
				else if (m->checkleft())
					m->mvleft();
			}
			else if (m->getDir() == 3)
			{
				if (m->checkleft())
					m->mvleft();
				else if (m->checkup())
					m->mvup();
			}
			else
			{
				if (m->checkleft())
					m->mvleft();
				else if (m->checkup())
					m->mvup();
			}
		}
		else if (ydiff > xdiff)
		{
			if (m->checkright())
				m->mvright();
			else if (m->checkdown())
				m->mvdown();
			else if (m->getDir() == 1)
			{
				if (m->checkup())
					m->mvup();
				else if (m->checkleft())
					m->mvleft();
			}
			else if (m->getDir() == 3)
			{
				if (m->checkleft())
					m->mvleft();
				else if (m->checkup())
					m->mvup();
			}
			else
			{
				if (m->checkleft())
					m->mvleft();
				else if (m->checkup())
					m->mvup();
			}
		}
		else if (ydiff < xdiff)
		{
			if (m->checkdown())
				m->mvdown();
			else if (m->checkright())
				m->mvright();
			else if (m->getDir() == 1)
			{
				if (m->checkup())
					m->mvup();
				else if (m->checkleft())
					m->mvleft();
			}
			else if (m->getDir() == 3)
			{
				if (m->checkleft())
					m->mvleft();
				else if (m->checkup())
					m->mvup();
			}
			else
			{
				if (m->checkleft())
					m->mvleft();
				else if (m->checkup())
					m->mvup();
			}
		}
	}
	else if (ydiff > 0 && xdiff < 0)
	{
		if (ydiff == abs(xdiff))
		{
			if (m->checkleft())
				m->mvleft();
			else if (m->checkdown())
				m->mvdown();
			else if (m->getDir() == 1)
			{
				if (m->checkup())
					m->mvup();
				else if (m->checkright())
					m->mvright();
			}
			else if (m->getDir() == 4)
			{
				if (m->checkright())
					m->mvright();
				else if (m->checkup())
					m->mvup();
			}
			else
			{
				if (m->checkright())
					m->mvright();
				else if (m->checkup())
					m->mvup();
			}
		}
		else if (ydiff > abs(xdiff))
		{
			if (m->checkleft())
				m->mvleft();
			else if (m->checkdown())
				m->mvdown();
			else if (m->getDir() == 1)
			{
				if (m->checkup())
					m->mvup();
				else if (m->checkright())
					m->mvright();
			}
			else if (m->getDir() == 4)
			{
				if (m->checkright())
					m->mvright();
				else if (m->checkup())
					m->mvup();
			}
			else
			{
				if (m->checkright())
					m->mvright();
				else if (m->checkup())
					m->mvup();
			}
		}
		else if (ydiff < abs(xdiff))
		{
			if (m->checkdown())
				m->mvdown();
			else if (m->checkleft())
				m->mvleft();
			else if (m->getDir() == 1)
			{
				if (m->checkup())
					m->mvup();
				else if (m->checkright())
					m->mvright();
			}
			else if (m->getDir() == 4)
			{
				if (m->checkright())
					m->mvright();
				else if (m->checkup())
					m->mvup();
			}
			else
			{
				if (m->checkright())
					m->mvright();
				else if (m->checkup())
					m->mvup();
			}
		}
	}
	else if (ydiff == 0 && xdiff < 0)
	{
		if (m->checkleft())
			m->mvleft();
		else if (m->checkupleft() && m->checkup())
			m->mvup();
		else if (m->checkdownleft() && m->checkdown())
			m->mvdown();
		else if (m->checkup())
			m->mvup();
		else if (m->checkdown())
			m->mvdown();
		else if (m->checkright())
			m->mvright();
	}
	else if (ydiff == 0 && xdiff > 0)
	{
		if (m->checkright())
			m->mvright();
		else if (m->checkupright() && m->checkup())
			m->mvup();
		else if (m->checkdownright() && m->checkdown())
			m->mvdown();
		else if (m->checkup())
			m->mvup();
		else if (m->checkdown())
			m->mvdown();
		else if (m->checkleft())
			m->mvleft();
	}
	else if (ydiff < 0 && xdiff == 0)
	{
		if (m->checkup())
			m->mvup();
		else if (m->checkupleft() && m->checkleft())
			m->mvleft();
		else if (m->checkupright() && m->checkright())
			m->mvright();
		else if (m->checkleft())
			m->mvleft();
		else if (m->checkright())
			m->mvright();
		else if (m->checkdown())
			m->mvdown();
	}
	else if (ydiff > 0 && xdiff == 0)
	{
		if (m->checkdown())
			m->mvdown();
		else if (m->checkdownleft() && m->checkleft())
			m->mvleft();
		else if (m->checkdownright() && m->checkright())
			m->mvright();
		else if (m->checkleft())
			m->mvleft();
		else if (m->checkright())
			m->mvright();
		else if (m->checkup())
			m->mvup();
	}
}

/* Game Mode Selection Panel, Easy, Medium, Hard */
int Engine::GameMode()
{
	int maxy, maxx;

	WINDOW* subwin = newwin(17, 43, (LINES / 2) - 5, (COLS / 2) - 21);
	wattron(subwin, COLOR_PAIR(1));
	box(subwin, 0, 0);
	keypad(subwin, true);

	maxy = getmaxy(subwin);
	maxx = getmaxx(subwin);

	mvwprintw(subwin, 3, (maxx / 2) - 11, "Select Game Difficulty");

	std::string options[3] = { "Easy", "Medium", "Hard" };
	int choice;
	int highlight = 0;

	while (1)
	{
		for (int i = 0; i < 3; i++)
		{
			if (options[i] == "Easy")
				mvwprintw(subwin, i*2 + (maxy / 2) + 1, (maxx / 2) - 2, options[i].c_str());
			else if (options[i] == "Medium")
				mvwprintw(subwin, i*2 + (maxy / 2) + 1, (maxx / 2) - 3, options[i].c_str());
			else if (options[i] == "Hard")
				mvwprintw(subwin, i*2 + (maxy / 2) + 1, (maxx / 2) - 2, options[i].c_str());
		}

		if (highlight == 0)
		{
			mvwaddch(subwin, highlight*2 + (maxy / 2) + 1, (maxx / 2) - 4, ACS_RARROW);
			mvwaddch(subwin, highlight*2 + (maxy / 2) + 1, (maxx / 2) + 3, ACS_LARROW);
		}
		if (highlight == 1)
		{
			mvwaddch(subwin, highlight * 2 + (maxy / 2) + 1, (maxx / 2) - 5, ACS_RARROW);
			mvwaddch(subwin, highlight * 2 + (maxy / 2) + 1, (maxx / 2) + 4, ACS_LARROW);
		}
		if (highlight == 2)
		{
			mvwaddch(subwin, highlight * 2 + (maxy / 2) + 1, (maxx / 2) - 4, ACS_RARROW);
			mvwaddch(subwin, highlight * 2 + (maxy / 2) + 1, (maxx / 2) + 3, ACS_LARROW);
		}

		choice = wgetch(subwin);

		if (highlight == 0)
		{
			mvwaddch(subwin, highlight * 2 + (maxy / 2) + 1, (maxx / 2) - 4, ' ');
			mvwaddch(subwin, highlight * 2 + (maxy / 2) + 1, (maxx / 2) + 3, ' ');
		}
		if (highlight == 1)
		{
			mvwaddch(subwin, highlight * 2 + (maxy / 2) + 1, (maxx / 2) - 5, ' ');
			mvwaddch(subwin, highlight * 2 + (maxy / 2) + 1, (maxx / 2) + 4, ' ');
		}
		if (highlight == 2)
		{
			mvwaddch(subwin, highlight * 2 + (maxy / 2) + 1, (maxx / 2) - 4, ' ');
			mvwaddch(subwin, highlight * 2 + (maxy / 2) + 1, (maxx / 2) + 3, ' ');
		}

		switch (choice)
		{
		case KEY_UP:
			highlight--;
			if (highlight == -1)
				highlight = 0;
			break;
		case KEY_DOWN:
			highlight++;
			if (highlight == 3)
				highlight = 2;
			break;
		}

		if (choice == 10)
			break;
		if (choice == 27)
			return 0;
	}

	wattroff(subwin, COLOR_PAIR(1));
	wclear(subwin);
	wrefresh(subwin);

	switch (highlight)
	{
	case 0:
		return 10;
	case 1:
		return 7;
	case 2:
		return 4;
	default:
		return 10;
	}
}

void Engine::setNewLoc(Movement * ch)
{
	char tmp;
	int y, x;
	y = x = 0;

	srand(time(0));

	y = (rand() % (map.size() - 1));
	x = (rand() % map[0].length());
	tmp = mvwinch(mapwin, y, x);
	while (tmp != ' ')
	{
		y = (rand() % (map.size() - 1));
		x = (rand() % map[0].length());
		tmp = mvwinch(mapwin, y, x);
	}

	ch->setyLoc(y);
	ch->setxLoc(x);
}

