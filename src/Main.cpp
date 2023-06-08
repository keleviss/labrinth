#include <stdlib.h>
#include <iostream>
#include <curses.h>
#include <windows.h>
#include "Engine.h"

#define _WIN32_WINNT 0x0500

using namespace std;

int main(int argc, char** argv)
{
	/* Make Window not Resizeable */
	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	Engine engine(1);
	int tmp;

	do{
		tmp = engine.InitMenu();

		engine.ExecMenuChoice(tmp);

	} while (tmp != 3);

	return 0;
}