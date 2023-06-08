#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <curses.h>
#include <panel.h>
#include <ctime>
#include <cstdlib>
#include <filesystem>
#include "Player.h"
#include "Gnome.h"
#include "Traal.h"
#include "Treasure.h"
#include "Movement.h"
#include "HighScore.h"
#include "Diamond.h"
#include "Location.h"

#define EASY 10
#define MEDIUM 7
#define HARD 4
#define mapy 23
#define mapx 73

class Engine
{
private:
	int gamesession;
	int menuoption;
	std::string enter_name;

	// map and score attributes
	std::vector<std::string> map;
	unsigned short int score;

	// game characters and objectives
	Player* player;
	std::vector<Traal*> traal;
	std::vector<Gnome*> gnomes;
	std::vector<Diamond*> diamonds;
	Treasure* treasure;
	HighScore* highscores;

	// game window
	WINDOW* gamewin;
	WINDOW* mapwin;
	WINDOW* scoreswin;
	WINDOW* helpwin;
	WINDOW* endgamewin;
	WINDOW* namewin;

public:
	//constructors, destructor
	Engine();
	Engine(int);
	~Engine();

	// Engine setups
	void Setup();

	// Menu Window
	int InitMenu();
	void ExecMenuChoice(int);

	// Menu Window Options
	void Play(int);
	void ShowTopScores();
	void Help();
	void Shutdown();
	void NewHighScore(int, int, int, int);

	// Game Outcomes
	void EndGameScreen();
	void GameOver();
	void GameWON();
	int GameMode();

	// Map Setup
	void LoadMap();
	void DrawMap();

	// Score Board Managing
	void InitHighScores();
	void SaveHighScores();
	void LoadHighScores();

	// Character Initializers
	void InitPotter();
	void InitTraal();
	void InitGnome();
	void InitDiamonds();
	void InitTreasure();
	void setNewLoc(Movement*);

	// Gnome and Traal Movement
	void gnomeMv(Movement*, Movement*);
	void traalMv(Movement*, Movement*);
};

#endif
