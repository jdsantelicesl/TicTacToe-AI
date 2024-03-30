#include<iostream>
#include<cmath>
#include<string>
using namespace std;

/*
Process : displays the current board to the terminal. 
          board array contains 1 for X, -1 for O, 0 for blank.
Input   : board board
Output  : None.
*/
void displayBoard(int board[]) {
    
    for(int i = 1; i <= 9; i++) {
        
        cout << " | ";

        if(board[i-1] == 1) {
            cout << "X";
        }
        else if (board[i-1] == -1) {
            cout << "O";
        }
        else {
            cout << " ";
        }
        if(i % 3 == 0) {
            cout << " |";
            cout << "\n";
            cout << " -------------" << endl;
        }
    }
}


/*
Process : Displays a menu for the user to pick if they 
          want to start againt as 'X' 'O' or Quit
Input   : From User
Output  : True if X, False if O
Comments: Might want to change from boolean to character for readability when
          forking modules with other modules
To Do   : Input Validation
*/
bool startingPlayer() {
    char user_input;
    cout << "Pick X or O: ";
    cin >> user_input;

    while (user_input != 'X' && user_input != 'O') {
        cout << "Invalid input. Please pick X or O: ";
        cin >> user_input;
    }

    return (user_input == 'X');
}

/*
Process  : Gets player input and changes the board in doing so.
Input:   + player: Boolean representing whos turn it is.
         + board: the board board.
Output   : the number of the square edited (0-8)
*/
int getInput(bool player, int board[]) {
    int val = 0;
    int set;
    bool cont = true;

    while(!(val >= 1 && val <= 9)) {
        if (player) {
            cout << "It is X's turn to move" << endl;
            set = 1;
        }
        else {
            cout << "It is O's turn to move" << endl;
            set = -1;
        }
        cout << "Please enter a square to make your move (1-9) : ";
        cin >> val;

        if(!(val >= 1 && val <= 9)) {
            cout << "Invalid input, please enter a number from 1-9" << endl;
            continue;
        }
        
        if(board[val-1] != 0) {
            cout << "This square is taken, please pick another" << endl;
            continue;
        }
        else {
            cont = false;
        }
    } while(!(val >= 1 && val <= 9));

    board[val-1] = set;
    return val-1;
}


/*
Process : Determins if there is a pattern for a winning game
Input   : 1 dimensional board array
Output  : returns X or O depending on winner
*/

char winner(int board[]) {
    // Define winning patterns indexes
    int winningPatterns[8][3] = {
        {0, 1, 2},  // Row 1
        {3, 4, 5},  // Row 2
        {6, 7, 8},  // Row 3
        {0, 3, 6},  // Column 1
        {1, 4, 7},  // Column 2
        {2, 5, 8},  // Column 3
        {0, 4, 8},  // Diagonal 1
        {2, 4, 6}   // Diagonal 2
    };

    // Check each winning pattern
    for (int i = 0; i < 8; ++i) {
        int a = winningPatterns[i][0];
        int b = winningPatterns[i][1];
        int c = winningPatterns[i][2];

        // Check if all elements in the pattern are the same and non-zero
        if (board[a] != 0 && board[a] == board[b] && board[a] == board[c]) {
            if (board[a] == 1) {
                return 'X'; // X wins if board[a] is 1
            } else if (board[a] == -1) {
                return 'O'; // O wins if board[a] is -1
            }
        }
    }

    // If no winning pattern is found
    return '\0'; // Return null character to indicate no winner yet
}

