#include <string>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int value;
    vector<Node*> children;
    int board[9];

    Node(int *arr)
    {
        for (int i = 0; i < 9; i++)
        {
            this->board[i] = *(arr + i);
        }
    }
    void addChild(Node *child)
    {
        children.push_back(child);
    }
    void setValue(int val) {
        value = val;
    }
};

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
int* result(int board[], int action, bool player){
    int *arr = new int[9];
    for(int i = 0; i < 9; i++) {
        arr[i] = board[i];
    }
    if(player) {
        arr[action] = 1;
    }
    else {
        arr[action] = -1;
    }
    return arr;
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

/*
 Process: Creates children for a node based on actions
 Input:
    actions: vector containing possible actions.
    head: The node to be expanded.
 Output: No output. Creates node children.
*/
void createChildren(vector<int> actions, Node *head, bool player) {

    for(int i = 0; i < static_cast<int>(actions.size()); i++) {
        int *arr = result(head->board, actions[i], player);
        head->addChild(new Node(arr));

    }
}
