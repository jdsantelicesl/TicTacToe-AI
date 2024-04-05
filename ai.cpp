#include "game.cpp"
#include <string>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;


// A function that looks for every possible actions.
// Push back the possible actions as indexes into a vector 
// Returns the vector.
vector<int> actions(int board[]){
    vector<int> possible_actions;
    for (int i = 0; i <= 8; i++){
        if (board[i] == 0){
            possible_actions.push_back(i);
        }
    }
    return possible_actions;
}

// Returns the result of the board after the given action
// 
//
int* result(int board[], vector<int> actions){
}

// Calculate the utility value of the current board state.
// Implement and return the utility value of the current board state.
// Returns 1 if 'X' wins, -1 if 'O' wins, and 0 for a draw or ongoing game.
int utility(int board[]){
    char win = winner(board);
    if (win == 'X')
        return 1;
    else if (win == 'O')
        return -1;
    else if (winner(board))
        return 0;

}

// Perform the Minimax algorithm to determine the best move for the current player.
// Implement and return the optimal utility value for the current player.
// Takes the current board state as input.
float minimax(int board[]){
    
}

