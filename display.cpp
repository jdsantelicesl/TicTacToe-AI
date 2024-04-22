#include<iostream>
#include<limits> // For data type checking
#include<cmath>
#include<string>
using namespace std;

/*
Process : displays the current board to the terminal. 
          board array contains 1 for X, -1 for O, 0 for blank.
Input   : board[]
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
Process  : Gets player input and changes the board in doing so.
Input:   + player: Boolean representing whos turn it is.
         + board: the board board.
Output   : the number of the square edited (0-8)
*/
int getInput(bool player, int board[]) {
    int val = 0;
    int set;
    bool cont = true;

    while(cont) {
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

        /*
            if(!cin) // or if(cin.fail())
            {
                // user didn't input a number
                cin.clear(); // reset failbit
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
                // next, request user reinput
            }
        */

        if(!(val >= 1 && val <= 9 || !cin.fail())) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input, please enter a number from 1-9" << endl;
            cont = true;
            continue;
        }

                
        if(board[val-1] != 0) {
            cout << "This square is taken, please pick another" << endl;
            cont = true;
            continue;
        }
        else {
            cont = false;
        }
    } 

    board[val-1] = set;
    return val-1;
}