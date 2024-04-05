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
            this->board[i] = *(arr+i);
        }
    }
    void addChild(Node *child)
    {
        children.push_back(child);
    }
};

// Calculate the utility value of the current board state.
// Implement and return the utility value of the current board state.
// Returns 1 if 'X' wins, -1 if 'O' wins, and 0 for a draw or ongoing game.
int utility(char board){

}

// Perform the Minimax algorithm to determine the best move for the current player.
// Implement and return the optimal utility value for the current player.
// Takes the current board state as input.
float minimax(char board){
    
}

/*
 Process: Creates children for a node based on actions
 Input:
    actions: vector containing possible actions.
    head: The node to be expanded.
 Output: No output. Creates node children.
*/
void createChildren(vector<int> actions, Node *head) {

    for(int i = 0; i < static_cast<int>(actions.size()); i++) {
        int *arr = result(head->board, actions[i]);
        head->addChild(new Node(arr));

    }
}
