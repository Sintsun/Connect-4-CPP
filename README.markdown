# Connect Four - C++ Console Game

A console-based implementation of the classic **Connect Four** game in C++. Two players take turns dropping checkers into a 6x7 grid, aiming to connect four checkers in a row—horizontally, vertically, or diagonally—before their opponent does.



## Features

- **Two-Player Gameplay**: Alternate turns with customizable checker symbols (`O` for Player 1, `X` for Player 2 by default).
- **Interactive Menu**: Start the game, adjust settings, view instructions, or check credits.
- **Input Validation**: Prevents invalid moves (e.g., full columns or out-of-range inputs).
- **Game Flexibility**: Quit mid-game or reset the board for a new match.
- **Win/Draw Detection**: Clearly displays victories or ties with an updated board.


*Screenshot showing the game board during play with `O` and `X` checkers placed.*

## Requirements

- **C++ Compiler**: g++, clang++, or any standard-compliant compiler.
- **Operating System**:
  - Windows: Uses `system("CLS")` for screen clearing.
  - Linux/macOS: Replace `system("CLS")` with `system("clear")`.
- **Terminal**: Must support ASCII characters for the board display.

## How to Play

1. **Start the Game**:
   - Launch the program to access the main menu.
   - Select `[1] Play` to begin a new game.

   ![Main Menu](images/mainmenu.png)  
   *Screenshot of the main menu with ASCII art and options (1-5).*

2. **Gameplay**:
   - The board is a 6x7 grid, with columns labeled **A-G** and rows numbered **1-6**.
   - Players enter a column (A-G) to drop their checker, which falls to the lowest empty slot.
   - Enter `Q` during a turn to quit (requires confirmation).
   ![Gameplay Board](images/game.png)  
3. **Winning Conditions**:
   - Connect **four checkers** in a row horizontally, vertically, or diagonally to win.
   - If all 42 slots are filled without a winner, the game ends in a **draw**.

   ![Win or Draw](images/game.png)  
   *Screenshot showing a win (e.g., four `O` checkers in a row) or draw state.*

4. **Settings**:
   - Select `[2] Settings` to:
     - Choose which player starts.
     - Change checker symbols (cannot be `+`, `-`, `|`, or space; must be unique).
   
   ![Settings Menu](images/settings.png)  
   *Screenshot of the settings menu.*

5. **Other Options**:
   - `[3] Instructions`: View detailed game rules.
   - `[4] Credits`: See the creator’s message.
   - `[5] Exit`: Quit the program.

   ![Instructions](images/instructions.png)  
   *Screenshot of the instructions screen.*

## Capturing Screenshots

To include screenshots in your README:

- **Windows**: Use Snipping Tool or `Win + Shift + S`. Save as `gameplay.png`, `menu.png`, etc.
- **Linux**: Use `gnome-screenshot` or `scrot` to capture the terminal.
- **macOS**: Press `Cmd + Shift + 4` to select the terminal window.
- **GitHub**: Store images in a folder (e.g., `screenshots/`) and link them using `![Alt Text](screenshots/image.png)`.

## Credits

Created with ❤️ by **Sintsun**. Inspired by the classic Connect Four game.
