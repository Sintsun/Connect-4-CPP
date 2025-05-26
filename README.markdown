# Connect Four Game - C++ Version

A console-based implementation of the classic Connect Four game in C++. Two players take turns dropping checkers into a 6x7 grid, aiming to connect four checkers in a row—horizontally, vertically, or diagonally—before their opponent does.

## Features

- Two-player gameplay with customizable checker symbols (`O` and `X` by default).
- Interactive menu with options to start the game, adjust settings, view instructions, or see credits.
- Input validation to prevent invalid moves (e.g., full columns or out-of-range inputs).
- Support for quitting mid-game and resetting the board for new matches.
- Clear win and draw detection with visual board updates.

\[Insert Screenshot 1: Gameplay Board\] *Place a screenshot here showing the game board during play (e.g., with some* `O` *and* `X` *checkers placed). This helps users visualize the interface right after reading the features.*

## Requirements

- C++ compiler (e.g., g++, clang++)
- Operating System: Windows (for `system("CLS")`) or Linux/macOS (replace `system("CLS")` with `system("clear")`)
- Terminal/console that supports ASCII characters

## How to Play

1. **Start the Game**:
    ![main](images/mainmenu.png)
   - Launch the program to see the main menu.
   - Select option `[1]` to start a new game.

   \[Insert Screenshot 2: Main Menu\] *Place a screenshot of the main menu here, showing the ASCII art and options (1-5). This helps users understand the navigation interface.*

2. **Gameplay**:
     ![game](images/game.png)
   - The board is a 6x7 grid, with columns labeled A-G and rows numbered 1-6.
   - Players take turns entering a column (A-G) to drop their checker (`O` for Player 1, `X` for Player 2).
   - The checker falls to the lowest empty slot in the chosen column.
   - Enter `Q` during a turn to quit the game (confirmation required).

3. **Winning**:

   - Connect four checkers in a row horizontally, vertically, or diagonally to win.
   - If the board fills (42 checkers) without a winner, the game ends in a draw.

4. **Settings**:
    ![game](images/settings.png)
   - Option `[2]` lets you choose which player starts or change checker symbols.
   - Symbols cannot be `+`, `-`, `|`, or space, and both players must have different symbols.

5. **Other Options**:
    ![instructions](images/instructions.png)
   - `[3] Instructions`: View game rules.
   - `[4] Credits`: See the creator’s message.
   - `[5] Exit`: Quit the program.

   \[Insert Screenshot 3: Win or Draw\] *Place a screenshot here showing a win (e.g., four* `O` *checkers in a row) or draw state. This illustrates the game’s end conditions and outcome display.*

## Capturing Screenshots

- **Windows**: Use the Snipping Tool or `Win + Shift + S` to capture the console during gameplay. Save as `gameplay.png`, `menu.png`, etc.
- **Linux**: Use `gnome-screenshot` or `scrot` to capture the terminal.
- **macOS**: Press `Cmd + Shift + 4` to select the terminal window and save the screenshot.
- **GitHub**: Place images in a folder (e.g., `screenshots/`) in your repository. Link them in the README using `![Description](screenshots/image.png)`.

## Credits

Created with love by Sintsun. Inspired by the classic Connect Four game.

---
