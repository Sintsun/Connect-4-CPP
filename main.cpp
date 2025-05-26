#include <iostream>
using namespace std;

class connectFour {
    char board[6][7];
    char players[2];
    int who; // 0 is player 1, 1 is player 2
    int checkerCount;

    bool inRngRow(int val) {
        return (0 <= val && val <= 5);
    }
    bool inRngCol(int val) {
        return (0 <= val && val <= 6);
    }
    
    bool checkDirections(int row, int col) {
        char current = board[row][col];
        
        // Horizontal
        int count = 1;
        for (int i = 1; i < 4; i++) {
            if (inRngCol(col + i) && board[row][col + i] == current) count++;
            else break;
        }
        for (int i = 1; i < 4; i++) {
            if (inRngCol(col - i) && board[row][col - i] == current) count++;
            else break;
        }
        if (count >= 4) return true;

        // Vertical
        count = 1;
        for (int i = 1; i < 4; i++) {
            if (inRngRow(row + i) && board[row + i][col] == current) count++;
            else break;
        }
        for (int i = 1; i < 4; i++) {
            if (inRngRow(row - i) && board[row - i][col] == current) count++;
            else break;
        }
        if (count >= 4) return true;

        // Diagonal (down-right and up-left)
        count = 1;
        for (int i = 1; i < 4; i++) {
            if (inRngRow(row + i) && inRngCol(col + i) && board[row + i][col + i] == current) count++;
            else break;
        }
        for (int i = 1; i < 4; i++) {
            if (inRngRow(row - i) && inRngCol(col - i) && board[row - i][col - i] == current) count++;
            else break;
        }
        if (count >= 4) return true;

        // Diagonal (down-left and up-right)
        count = 1;
        for (int i = 1; i < 4; i++) {
            if (inRngRow(row + i) && inRngCol(col - i) && board[row + i][col - i] == current) count++;
            else break;
        }
        for (int i = 1; i < 4; i++) {
            if (inRngRow(row - i) && inRngCol(col + i) && board[row - i][col + i] == current) count++;
            else break;
        }
        if (count >= 4) return true;

        return false;
    }

public:
    connectFour() {
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 7; j++)
                board[i][j] = ' ';
        who = 0;
        players[0] = 'O';
        players[1] = 'X';
        checkerCount = 0;
    }

    void printBoard() {
        cout << "   ";
        for (int i = 0; i < 7; i++)
            cout << char(65 + i) << " ";
        cout << endl << "  " << '+';
        for (int i = 0; i < 14; i++)
            cout << '-';
        cout << '+' << endl;
        for (int i = 0; i < 6; i++) {
            cout << i + 1 << " " << '|';
            for (int j = 0; j < 7; j++)
                cout << board[i][j] << " ";
            cout << '|' << endl;
        }
        cout << "  " << '+';
        for (int i = 0; i < 14; i++)
            cout << '-';
        cout << '+' << endl;
    }

    char getPlayerSymbol(int a) {
        return players[a];
    }
    
    void setPlayerSymbol(int which, char a) {
        players[which] = a;
    }

    int getCurrentPlayer() const {
        return who;
    }
    
    void swapPlayers() {
        who = !who;
    }
    
    bool dropChecker(char checker) {
        checker = toupper(checker);
        if (checker >= 'A' && checker <= 'G') {
            for (int i = 5; i >= 0; i--) {
                if (board[i][checker - 'A'] == ' ') {
                    board[i][checker - 'A'] = players[who];
                    checkerCount++;
                    return true;
                }
            }
        }
        return false;
    }
    
    bool checkWin() {
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 7; j++)
                if (board[i][j] != ' ' && checkDirections(i, j))
                    return true;
        return false;
    }
    
    bool checkDraw() const {
        return checkerCount == 42;
    }
    
    void resetGame() {
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 7; j++)
                board[i][j] = ' ';
        checkerCount = 0;
        who = 0;
    }
};

class Game {
    connectFour game;
    
    bool quit() {
        char choice;
        cout << "*************Q U I T*****************\n\n";
        cout << "Are you sure you want to quit?\n";
        cout << "Enter 'Y' for yes and 'N' for no: ";
        cin >> choice;
        cin.ignore(10000, '\n');
        choice = toupper(choice);
        
        while (choice != 'Y' && choice != 'N') {
            cout << "Invalid choice, please enter either 'Y' or 'N': ";
            cin >> choice;
            cin.ignore(10000, '\n');
            choice = toupper(choice);
        }
        return choice == 'Y';
    }
    
    void play() {
        char choice;
        while (true) {
            system("CLS");
            game.printBoard();
            cout << "Player " << game.getCurrentPlayer() + 1 << "'s turn:" << endl;
            cout << "Enter move (A-G or Q to quit): ";
            cin >> choice;
            cin.ignore(10000, '\n');
            
            while (!game.dropChecker(choice)) {
                if (toupper(choice) == 'Q') {
                    if (quit()) {
                        game.resetGame();
                        return;
                    }
                    cout << "Resuming Game\n\n";
                } else {
                    cout << "Invalid move!!" << endl;
                }
                cout << "Enter move (A-G or Q to quit): ";
                cin >> choice;
                cin.ignore(10000, '\n');
            }
            
            system("CLS");
            game.printBoard();
            
            if (game.checkWin()) {
                cout << "Player " << game.getCurrentPlayer() + 1 << " wins!" << endl;
                cout << "Press Enter to continue\n";
                cin.get();
                break;
            }
            if (game.checkDraw()) {
                cout << "Draw game" << endl;
                cout << "Press Enter to continue\n";
                cin.get();
                break;
            }
            game.swapPlayers();
        }
        game.resetGame();
    }
    
    void printMenu() {
        cout << "  ___  __   __ _  __ _  ____  ___  ____    ____  __   _  _  ____  \n";
        cout << " / __)/  \\ (  ( \\(  ( \\(  __)/ __)(_  _)  (  __)/  \\ / )( \\(  _ \\ \n";
        cout << "( (__(  O )/    //    / ) _)( (__   )(     ) _)(  O )) \\/ ( )   / \n";
        cout << " \\___)\\__/ \\_)__)\\_)__)(____)\\___) (__)   (__)  \\__/ \\____/(__\\_) \n\n\n";
        cout << " ***Game Menu***\n";
        cout << "[1] Start Game\n";
        cout << "[2] Settings\n";
        cout << "[3] Instructions\n";
        cout << "[4] Credits\n";
        cout << "[5] Exit\n";
        cout << "*****************\n";
    }
    
    void printSettings() {
        cout << "***Settings Menu***\n";
        cout << "[1] Who starts first\n";
        cout << "[2] Checker symbols\n";
        cout << "[3] Return to Game Menu\n";
        cout << "*********************\n";
        cout << "Option(1 - 3): \n";
    }
    
    bool isBoundrySymbol(char a) {
        char arr[4] = {'+', '-', '|', ' '};
        for (int i = 0; i < 4; i++)
            if (a == arr[i])
                return false;
        return true;
    }
    
    void settings() {
        char choice;
        while (true) {
            system("CLS");
            printSettings();
            cin >> choice;
            cin.ignore(10000, '\n');
            
            if (choice == '1') {
                cout << "currently player " << game.getCurrentPlayer() + 1 << " goes first.\n";
                cout << "enter 'Y' to change to other player, enter 'N' to cancel\n";
                cin >> choice;
                cin.ignore(10000, '\n');
                choice = toupper(choice);
                
                while (choice != 'Y' && choice != 'N') {
                    cout << "Invalid choice, please enter either 'Y' or 'N': ";
                    cin >> choice;
                    cin.ignore(10000, '\n');
                    choice = toupper(choice);
                }
                system("CLS");
                if (choice == 'Y') {
                    game.swapPlayers();
                    cout << "Now player " << game.getCurrentPlayer() + 1 << " goes first.\n";
                }
                printSettings();
            }
            else if (choice == '2') {
                char p1, p2;
                cout << "Player 1's symbol: " << game.getPlayerSymbol(0) << endl;
                cout << "Player 2's symbol: " << game.getPlayerSymbol(1) << endl;
                cout << "Enter what would you like to change player 1's symbol to: ";
                cin >> p1;
                cin.ignore(10000, '\n');
                
                while (!isBoundrySymbol(p1)) {
                    cout << "Invalid symbol!\nPlease enter again for player 1: ";
                    cin >> p1;
                    cin.ignore(10000, '\n');
                }
                
                cout << "Enter what would you like to change player 2's symbol to: ";
                cin >> p2;
                cin.ignore(10000, '\n');
                
                while (!isBoundrySymbol(p2)) {
                    cout << "Invalid symbol!\nPlease enter again for player 2: ";
                    cin >> p2;
                    cin.ignore(10000, '\n');
                }
                
                system("CLS");
                if (p1 == p2) {
                    cout << "Both players can't have the same symbol, resetting to default\n";
                } else {
                    game.setPlayerSymbol(0, p1);
                    game.setPlayerSymbol(1, p2);
                    cout << "Player 1's symbol: " << game.getPlayerSymbol(0) << endl;
                    cout << "Player 2's symbol: " << game.getPlayerSymbol(1) << endl;
                }
                printSettings();
            }
            else if (choice == '3') {
                return;
            }
            else {
                cout << "Please enter a valid input from 1-3: ";
                cin.ignore(10000, '\n');
            }
        }
    }
    
    void instructions() {
        cout << "*******************INSTRUCTIONS**************************************\n\n";
        cout << "Enter A-G to drop your corresponding tile in the designated column\n";
        cout << "You have to connect four of your tiles in a straight line either\n";
        cout << "in horizontally, vertically or diagonally to win. The game will be\n";
        cout << "Draw if the board fills up with neither of the player having 4 connected\n";
        cout << "tiles.\n\nPress Enter to go back";
        cin.get();
    }
    
    void credits() {
        cout << "*******************CREDITS**************************************\n\n";
        cout << "This game was created by me ^o^\n\n";
        cout << "Press Enter to go back";
        cin.get();
    }

public:
    Game() {}
    
    void gameLoop() {
        char choice;
        while (true) {
            system("CLS");
            printMenu();
            cin >> choice;
            cin.ignore(10000, '\n');
            system("CLS");
            
            if (choice == '1') {
                play();
            }
            else if (choice == '2') {
                settings();
            }
            else if (choice == '3') {
                instructions();
            }
            else if (choice == '4') {
                credits();
            }
            else if (choice == '5') {
                if (quit())
                    return;
            }
            else {
                cout << "Please enter a valid input from 1-5: ";
                cin.get();
            }
        }
    }
};

int main() {
    Game game;
    game.gameLoop();
    return 0;
}