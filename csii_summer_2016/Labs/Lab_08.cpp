/*
    Author: Nathan Tompkins
    Course: COSC 1337 Summer 2016 MW16
    Instructor: Paul Thayer
    Lab 8: Tic Tac Toe
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

// Class that makes a new board
class Board {
    
    private:
    // Board Design
        static const int board_size=3; 
        char board[board_size][board_size];
    // Player Dependent Variables
        int currentPlayer=0,    // Update to either 1 or 2
            playerMove=0;       // Update from board min to board max 
    
        char playerSymbol=' ';  // Update to X or O
    // Tallies
        int playerOneWins=0,    // Record wins for player one
            playerTwoWins=0,    // Record wins for player two
            catsGames=0;        // Record cat's games/no winner
    // Sentinel
        bool gameState=true;    // While true, games continue
        
    public:
    // Accessors 
        char getValueOf(int x, int y) { 
            return board[x][y];     // Return value of any space on the board
        }
        int getCurrentPlayer() {
            return currentPlayer;   // Return current player, 1 or 2
        }
        char getPlayerSymbol() {
            return playerSymbol;    // Return which symbol, X or O, is being used
        }
        bool getGameState() {
            return gameState;       // Return the game state
        }
    
    // Mutators Prototypes
        void setValueOf(int x, int y); // Sets new value of place on grid
        void setCurrentPlayer(int p);               // Sets current player, 1 or 2
        void setPlayerSymbol(int currentPlayer);
        void setPlayerMove(int m);
        void setGameState(bool);
        
    // Other function prototypes
        void show(); // Prototype to display board
        // prototype to output prompt and input a value that is transferred to playerMove
        int input(string intro, int currentPlayer, string prompt, string error);
        bool isValidMove(int x); // Returns true if move is in empty spot on board
        int switchPlayer(int player);
    // Constructor
    Board() {
        // cout << "Const working.\nBoard size: " << board_size << endl;
        // Assign default value to each space on the grid
        board[1][1] = '1';
        board[1][2] = '2';
        board[1][3] = '3';
        board[2][1] = '4';
        board[2][2] = '5';
        board[2][3] = '6';
        board[3][1] = '7';
        board[3][2] = '8';
        board[3][3] = '9';
        // int valueOfPosition=0; // Increment board size by 1
        // for (int xSize=1; xSize < board_size + 1; ++xSize)
        // {
        //     // cout << "x Size: " << xSize << endl;
        //     for(int ySize=1; ySize < board_size + 1; ++ySize) {
        //         // cout << "y Size: " << ySize << endl;
        //         ++valueOfPosition;
        //         // cout << valueOfPosition << endl;
        //         board[xSize][ySize] = static_cast<char>(valueOfPosition);
        //     }
        // }
    }
};    

// Mutators Expanded //

// Updates player symbol to char 'X' or char 'O'
void Board::setPlayerSymbol(int currentPlayer) {
    if (currentPlayer == 1)
        playerSymbol = 'X';
    else
        playerSymbol = 'O';
}

int Board::switchPlayer(int player) {
    if (player == 0) {
        player = 1;
        return player;
    }
    else if (player == 1) {
        player = 2;
        return player;
    }
    else {
        player = 1;
        return player;
    }
}

// Updates which player is moving
void Board::setCurrentPlayer(int p) {
    if(p == 1 || p == 2)    // Only valid for 2 players
        currentPlayer = p;
    else 
        return;
}

// Changes value of position in grid to either X or O               !!!
void Board::setPlayerMove(int m) {
    switch(m) {
        case(1):
            board[1][1] = playerSymbol;
            break;
        case(2):
            board[1][2] = playerSymbol;
            break;
        case(3):
            board[1][3] = playerSymbol;
            break;
        case(4):
            board[2][1] = playerSymbol;
            break;
        case(5):
            board[2][2] = playerSymbol;
            break;
        case(6):
            board[2][3] = playerSymbol;
            break;
        case(7):
            board[3][1] = playerSymbol;
            break;
        case(8):
            board[3][2] = playerSymbol;
            break;
        case(9):
            board[3][3] = playerSymbol;
            break;
        default:
            cout << "\nInvalid Move.\n";
            break;
    }
}

// Validate input for range of board, and against already filled spaces
bool Board::isValidMove(int x) {
    if (x <= board_size && x > 0)       // Need to evaluate for already used spaces !!!!!!!!
        return true;
    else 
        return false;
}

// Function to obtain input
int Board::input(string intro, int currentPlayer, string prompt, string error) {
    // Ouput custom prompt
    cout << intro << currentPlayer << prompt;
    // Return player's move
    cin >> playerMove;
    return playerMove;
}

// Display Board
void Board::show() {
    // First row
    cout    << endl;
    cout    << getValueOf(1,1) 
            << ' ' << '|' << ' ' 
            << getValueOf(1,2) 
            << ' ' << '|' << ' '
            << getValueOf(1,3) 
            << endl << "- - - - -" 
            << endl;
    // Second row      
    cout    << getValueOf(2,1) 
            << ' ' << '|' << ' ' 
            << getValueOf(2,2) 
            << ' ' << '|' << ' ' 
            << getValueOf(2,3) 
            << endl << "- - - - -" 
            << endl;
    // Third row       
    cout    << getValueOf(3,1) 
            << ' ' << '|' << ' ' 
            << getValueOf(3,2) 
            << ' ' << '|' << ' ' 
            << getValueOf(3,3) 
            << endl;
}

int main() {
    
    // Welcome message
    cout << "Tic Tac Toe\n";
    
    // Create new board object
    Board thisBoard;
    
    int player=0; // variable to update player, must be 1 or 2
    
    while(thisBoard.getGameState()) {     // Continue playing until the player quits
        // display board + grid
        thisBoard.show();
        
        // Prepare round for player
        // Set player to 0
        player = thisBoard.switchPlayer(player); // Switch to player 1, then alternate between 1 and 2
        
        // Updates user listed
        thisBoard.setCurrentPlayer(player); // Set currentPlayer variable to 1 or 2
        thisBoard.setPlayerSymbol(player); // Change to X for player 1, or O for player 2
        char symbol = thisBoard.getPlayerSymbol(); // Variable to hold either symbol
        
        // prompt for player to enter input
        int move = thisBoard.input("\nPlayer #", \
            thisBoard.getCurrentPlayer(), \
            " make your move: ", \
            "\nError, please enter a valid spot.\n");
        
        if (true) {// thisBoard.isValidMove(move)) {
            // Have to validate that space is within bounds, and is not occupied !!!
            thisBoard.setPlayerMove(move);
        } else {
            cout << "NOT A VALID MOVE!\n";
        }
        
        // Clear the screen for next render
        cout << "\x1B[2J\x1B[H";
    }
        // Update board
        // thisBoard.setPlayerMove();
        
        // evaluate if game is over 
        
        
        
         
    // set value of position to player's symbol, X or O
    
    
        // if not game not over, then:
            // update player to next
            // display new version board
            //   and loop
        // if else one player won
            // check last move made for the player's id
            // update games won counter
        // else game is over and neither player one
            // update cat's game counter
    
    // print out results of games so far
    // ask another game should be played
        // if another game:
            // deconstruct old board
            // construct new board
            // continue to top  !check for retained scores
            
        // else
            // goodbye message!
    return 0;
}



/////////////////////////////////////////////////////////////////
// #include <iostream>
// #include <iomanip>
// using namespace std;

// class Board {
    
//     private:
//         // Create grid of values, begin with 3x3
//         char board[3][3];
        
//         // Current turn
//         int playerOneMove=0, 
//             playerTwoMove=0;
            
//         // Game record
//         int playerOneWins=0,
//             playerTwoWins=0,
//             catsGames=0;
            
//         // Game status
//         bool gameOver=false;
        
//     public:
//         void setPlayerOneMove(int p1, int min, int max);    // Takes input of destination and checks validity
//         void setPlayerTwoMove(int p2, int min, int max);    // ^^^
//         void setPlaceValue(int pv);                         // Sets value of player's move if valid, not called otherwise
        
//         void setPlayerOneWins(int p1w);                     // Logs wins of player #1
//         void setPlayerTwoWins(int p2w);                     // Logs wins of player #2
//         void setCatsGames(int cg);                          // Log cat's games
        
//         Board() // Constructor
//         {
//             cout << "\nConstructor working.\n\n";
//             // Set default values for the grid
//             board[1][1] = '1';
//             board[1][2] = '2';
//             board[1][3] = '3';
//             board[2][1] = '4';
//             board[2][2] = '5';
//             board[2][3] = '6';
//             board[3][1] = '7';
//             board[3][2] = '8';
//             board[3][3] = '9';
            
//         }
        
//         // GETTERS
//         char getValueOf(int i=0, int j=0) {
//             return board[i][j];
//         }
//         // bool validMove(int position);
        
//         // SETTERS
//         void setValueOf(char playerSymbol, int i=0, int j=0) {
//             board[i][j] = playerSymbol;
//         }
// };

// void Board::setPlayerOneMove(int p1, int min, int max) {
//     if (p1 < max && p1 > min )// And move is valid position 
//     {
//         playerOneMove = p1;
//     }
//     // else return error
// }

// void Board::setPlayerTwoMove(int p2, int min, int max) {    
//     if (p2 < max && p2 > min )// And move is valid position 
//     {
//         playerOneMove = p2;
//     }
//     // else return error
// }
// // void Board::setPlaceValue(char pv, int i, int j) {
// //     // board[i][j] = pv;
// // }

// void Board::showBoard()
// // void setPlayerOneWins(int p1w);
// // void setPlayerTwoWins(int p2w);
// // void setCatsGames(int cg);

// int main() {
    
//     Board current_board;
//     // Show the board
//     cout    <<' '<< current_board.getValueOf(1,1) <<' '<<'|'
//             <<' '<< current_board.getValueOf(1,2) <<' '<<'|'
//             <<' '<< current_board.getValueOf(1,3) << endl
//             << "- - - - - -" << endl
//             <<' '<< current_board.getValueOf(2,1) <<' '<<'|'
//             <<' '<< current_board.getValueOf(2,2) <<' '<<'|'
//             <<' '<< current_board.getValueOf(2,3) << endl
//             << "- - - - - -" << endl
//             <<' '<< current_board.getValueOf(3,1) <<' '<<'|'
//             <<' '<< current_board.getValueOf(3,2) <<' '<<'|'
//             <<' '<< current_board.getValueOf(3,3) << endl
//             << endl;
    
//     while (bool loopMenu=true) {
//         int current_player = 1;     // getCurrentPlayer(pass player number and player symbol);
//         char playerSymbol = 'X';    // currentPlayerSymbol;
        
//         cout << "Player " << current_player << " enter a position to move: ";   
//         int position = 0;
//         cin >> position;
//         current_board.setValueOf(position);
//         // int current_move=0;
//         // cin >> current_move;
        
//         // int min = 1, max = 9;
//         // if (current_move <= max && current_move >= min) {
//         //     cout << "Previous move: " << current_move << endl;
//         //     // Update value of grid
//         //     // getValueOf(i, j);
//         //     current_board.setValueOf('X');
//         //     loopMenu = false;
//         // }
//         // else {
//         //     cout << "Error, please enter a valid number." << endl;
//         // }
//     }
    
//     // get input 1 - 9
//     // int position = 0;
//     // cin >> position;
//     // if (position >=1 && position <=9)
//     // {
//     //     // verify the spot is empty
//     //     if (board.validMove(position))
//     //     {
//     //         board.setGrid[position];
//     //     }
//     //     else
//     //     {
//     //         cout << errMsg;
//     //     }
//     // }
//     // else {
//     //     string errMsg = 
//     //         "Error, please enter a number between 1 and 9 that has not already been played.";
//     //     cout << errMsg;
//     // }
    
//     return 0;
// }
