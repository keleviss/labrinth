# LABRINTH - A Terminal-Based Maze Game

Welcome to the repository for **LABRINTH**, a maze game developed in C++ using the PDCurses library. Inspired by the classic Pacman, this game offers a unique and challenging experience with multiple difficulty levels and a customizable map. It is designed specifically for Windows Terminal and is not supported on other operating systems.

## Table of Contents

- [Game Overview](#game-overview)
- [Features](#features)
- [Technologies Used](#technologies-used)
- [Installation](#installation)
- [Usage](#usage)
- [Game Modes](#game-modes)
- [Custom Maps](#custom-maps)
- [Potential Improvements](#potential-improvements)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Game Overview

**LABRINTH** is a terminal-based maze game where you navigate through a labyrinth filled with enemies that chase you based on simple movement logic. The game offers three difficulty levels, a scoreboard system, and the ability to customize the maze map. Though inspired by Pacman, the gameplay is distinct, providing a fresh take on the maze genre.

## Features

- **Three Difficulty Levels**: Choose between Easy, Medium, and Hard modes to match your skill level.
- **Customizable Map**: Modify the map by editing a text file to create your own custom labyrinth.
- **Scoreboard**: The game saves your high scores in a binary file, so you can keep track of your progress.
- **Simple Enemy AI**: Enemies use basic movement logic, with potential for future enhancement to more advanced AI.
- **Windows Terminal Support**: Designed exclusively for Windows Terminal, ensuring optimal performance on this platform.

## Technologies Used

- **C++**: The core programming language used for developing the game.
- **PDCurses Library**: Handles the graphical rendering in the terminal.
- **Windows Terminal**: The platform required to run the game.

## Installation

To install and play **LABRINTH** on your Windows system, follow these steps:

1. **Clone the repository**:

   ```bash
   git clone https://github.com/keleviss/labrinth
   ```

2. **Navigate to the project directory**:

   ```bash
   cd labrinth
   ```

4. **Run the game**:
   Execute/Run the game `LABRINTH.exe` as an "Admin"
   

## Usage

- **Starting the Game**: Launch the game from Windows Terminal by executing the compiled `.exe` file.
- **Selecting Game Mode**: Choose from Easy, Medium, or Hard modes.
- **Scoreboard**: Your scores are saved in the `scoreboard.bin` file located in the `gamefiles` folder.
- **Custom Maps**: Edit the `map.txt` file in the `gamefiles` folder to create and play with custom maps.

## Game Modes

**LABRINTH** offers three distinct game modes:

1. **Easy**: Slower enemy speed and more lives, suitable for beginners.
2. **Medium**: A balanced challenge with moderate enemy speed.
3. **Hard**: Fast-paced and difficult, with quicker enemies and fewer lives.

## Custom Maps

The game map is stored in a `map.txt` file in the `gamefiles` folder. You can create custom maps by modifying this file, following the structure of the existing map. Please note that custom maps have not been extensively tested; report any issues you encounter.

## Potential Improvements

While the game currently uses basic movement logic for enemies (implemented through nested `if` statements), there is potential to enhance the gameplay by incorporating more advanced algorithms for enemy AI. This could include pathfinding algorithms like A* to make enemies smarter and more challenging.

## Project Structure

```plaintext
labrinth/
│
├── src/                       # C++ source files
├── screenshots/               # Game screenshots
├── Release/
│   labrinth.exe               # Compiled game executable
│   pdcurses.dll               # PDCurses library files
│   ├── gamefiles/
│       ├── map.txt            # Default game map
│       └── scoreboard.bin     # Binary file storing the scoreboard
├── README.md                  # Project README file
├── CONTRIBUTING.md            # Contributing guidelines
└── LICENSE                    # License
```

## Contributing

Contributions are welcome! If you have ideas for improving the game, such as implementing smarter enemy AI or enhancing other aspects of gameplay, please fork the repository and submit a pull request. Ensure that your code is well-documented and follows the project's coding standards.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Contact

For any questions or suggestions, feel free to contact:

- **Your Name** - [your.email@example.com](mailto:kelesidisvissarion@gmail.com)
- **GitHub** - [https://github.com/yourusername](https://github.com/keleviss)
