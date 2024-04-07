#include <string>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int value = -5; // -5 is just used as a null placeholder. There is no null of int :(
    vector<Node*> children;
    int board[9];
    bool playerTurn;

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
    void setPlayer(bool turn) {
        playerTurn = turn;
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
void minimax(Node *head) {

    if(head->children.empty()) {
        return;
    }

    // If it is currently X's turn, it will be O's turn next. We need to pick the smallest value from children.
    if(head->playerTurn) { 
        int smallest = 2;
        for(int i = 0; i < static_cast<int>(head->children.size()); i++) {
            if(head->children[i]->value == -5) {
                minimax(head->children[i]);
            }
            if(head->children[i]->value < smallest) {
                smallest = head->children[i]->value;
            }
        }
        head->setValue(smallest);
    }

    // If it is currently O's turn, it will be X's turn next. We need to pick the largest value from children.
    else if(!head->playerTurn) {
        int largest = -2;
        for(int i =0; i < static_cast<int>(head->children.size()); i++) {
            if(head->children[i]->value == -5) {
                minimax(head->children[i]);
            }
            if(head->children[i]->value > largest) {
                largest = head->children[i]->value;
            }
        }
        head->setValue(largest);
    }
    
}

/*
 Process: Creates children for a node based on actions. Then calls upon itself recursively until tree has been built.
 Input:
    actions: vector containing possible actions.
    head: The node to be expanded.
    player: player's turn
 Output: No output. Creates node children.
*/
void createChildren(vector<int> possibleActions, Node *head, bool player) {
    head->setPlayer(player); 

    for(int i = 0; i < static_cast<int>(possibleActions.size()); i++) {
        int *arr = result(head->board, possibleActions[i], player);
        head->addChild(new Node(arr));

        char state = winner(head->children[i]->board);

        if (!state) { 
            createChildren(actions(head->children[i]->board), head->children[i], getPlayer(player));
        }
        else {
            if(state == 'X') {
                head->children[i]->setValue(1);
            }
            else if(state == 'O') {
                head->children[i]->setValue(-1);
            }
            else if(state == 'D') {
                head->children[i]->setValue(0);
            }
        }

    }
}
