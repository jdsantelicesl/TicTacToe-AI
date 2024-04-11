#include<iostream>
#include<cmath>
#include<string>
using namespace std;

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

    while (user_input != 'X' && user_input != 'O' && user_input != 'x' && user_input != 'o') {
        cout << "Invalid input. Please pick X or O: ";
        cin >> user_input;
    }

    return (user_input == 'X' || user_input == 'x');
}


/*
Process : Alternates between each player, X <-> O
Input   : The current player if X or O
Output  : Return True  | if current = X    
          Return False | if current = O    
*/
bool getPlayer(bool current){
    return !current;
}

/*
Process : Determins if there is a pattern for a winning game or draw
Input   : 1 dimensional board array
Output  : returns X or O depending on winner
*/
char winner(int board[]) {

    char retVal = 'D'; // Need it for draw check

    // Define winning patterns indexes
    int winning_patterns[8][3] = {
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
        int a = winning_patterns[i][0];
        int b = winning_patterns[i][1];
        int c = winning_patterns[i][2];

        // Check if all elements in the pattern are the same and non-zero
        if (board[a] != 0 && board[a] == board[b] && board[a] == board[c]) {
            if (board[a] == 1) {
                return 'X'; // X wins if board[a] is 1
            } else if (board[a] == -1) {
                return 'O'; // O wins if board[a] is -1
            }
        }

        // Need to check if draw for creating tree
        if(board[i] == 0 || board[8] == 0) {
            retVal = '\0';
        }

    }    
        return retVal; // Return null character to indicate no winner

}