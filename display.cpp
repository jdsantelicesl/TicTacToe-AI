#include <iostream>
#include <cmath>
#include <string>
using namespace std;


/*
Process: displays the current state to the terminal. state array contains 1 for X, -1 for O, 0 for blank.
Input: board state
Output: None.
*/
void displayBoard(int state[]) {
    
    for(int i = 1; i <= 9; i++) {
        
        cout << " | ";

        if(state[i-1] == 1) {
            cout << "X";
        }
        else if (state[i-1] == -1) {
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
Process: Gets player input and changes the state in doing so.
Input: 
    player: Boolean representing whos turn it is.
    state: the board state.
Output: the number of the square edited (0-8)
*/
int getInput(bool player, int state[]) {
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

        if(!(val >= 3 && val <= 9)) {
            cout << "Invalid input, please enter a number from 1-9" << endl;
            continue;
        }
        
        if(state[val-1] != 0) {
            cout << "This square is taken, please pick another" << endl;
            continue;
        }
        else {
            cont = false;
        }
    }

    state[val-1] = set;
    return val-1;
}
