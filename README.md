# Labrinth - A Terminal-Based Maze Game

![Game Screenshot](screenshots/gameplay.png)

## Overview

Welcome to Labrinth, a thrilling terminal-based maze game written in C++! Embark on a challenging journey through intricate mazes, solve puzzles, and aim for the highest scores. With the "LABRINTH.exe" executable, you can dive right into the action.

## Table of Contents

- [Installation](#installation)
- [How to Play](#how-to-play)
- [Directory Structure](#directory-structure)
- [Screenshots](#screenshots)
- [Contributing](#contributing)
- [License](#license)

## Installation

To get started with Labrinth, follow these steps:

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/your-username/labrinth.git

2. **Run the Game**

   Navigate to the "Release" directory:

   ```bash
   cd labrinth/Release
   ```

   Execute the game:
   ```bash
   ./LABRINTH.exe
   ```

   Ensure that the "pdcurses.dll" file is in the same directory as "LABRINTH.exe" to run the game successfully.

## How to Play

1. Objective:

   Your goal is to navigate throught the challenging maze, gather all the Diamonds '♦', reveal the Tresure '$', and reach it in order to win the game.

   But, be careful because there are wild Gnomes '¤' lurking and big Traals '£'. Don't let them catch you because they will eat you.

2. Controls:

   Use the arrow keys to move your character '@'.

3. Difficulties

   The game has 3 level difficulties, Easy, Medium and Hard.
   Don't be afraid to challenge yourself.

## Directory Structure

The repository is organized as follows:

- Release: Contains the pre-built game executable and required files.

   - LABRINTH.exe: The game executable.
   - pdcurses.dll: A required dynamic link library.
   - gamefiles: Additional game files.
      - map.txt: Maze configuration in text format.
      - scores.bin: Binary file to store high scores.

- src: Contains the source code for the Labrinth game.
  - All the C++ (.cpp) and header (.h) files used to create the game.
  - map.txt: Maze configuration for development/testing.
  - scores.bin: High scores file for development/testing.

## Screenshots

Gameplay Screenshot 1

Gameplay Screenshot 2

## Contributing

Contributions are welcome! If you want to contribute to this project, please follow the guidelines outlined in [CONTRIBUTING.md](#CONTRIBUTING.md).

## License

This project is licensed under [Apache License](https://github.com/keleviss/labrinth/blob/main/LICENSE).

* * *

Enjoy the Labrinth maze adventure, and may your scores be legendary!
