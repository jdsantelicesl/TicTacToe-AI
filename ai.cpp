#include <string>
#include <iomanip>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Node
{
public:
    int value = -5; // -5 is just used as a null placeholder. There is no null of int :(
    vector<Node*> children;
    int board[9];
    bool playerTurn;
    int action; // action taken to reach this state from parent.
    int bestAction = -5; // best action that can be chosen
    shared_ptr<Node> parent;

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
    void setAction(int act) {
        action = act;
    }
    void setBest(int best) {
        bestAction = best;
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
        
    return 0;

}

shared_ptr<Node> findPath(const shared_ptr<Node> child, shared_ptr<Node> head)
{
    cout << "Find path func" << endl;
    Node *childPtr = child.get();    // get() gets value of raw pointer from shared_ptr
    Node *parentPtr = child->parent.get(); 
    while (parentPtr != head.get())
    {
        parentPtr->setValue(childPtr->value);
        childPtr = parentPtr;
        parentPtr = parentPtr->parent.get();
    }

    head->setBest(childPtr->action);

    shared_ptr<Node> newHead(childPtr);
    cout << newHead->action << endl;
    return newHead;
}

void printQueue(vector<int> actions) {
    for(int i = 0; i < static_cast<int>(actions.size()); i++) {
        cout << actions[i];
    }
}

// Perform the Minimax algorithm to determine the best move for the current player.
// Implement and return the optimal utility value for the current player.
// Takes the current board state as input.
shared_ptr<Node> minimax(shared_ptr<Node> head, bool player) {
    cout << "Minimax func " << endl;
    // Node queue for BFS
    vector<shared_ptr<Node>> queue;

    // possible solution stacks
    vector<shared_ptr<Node>> draw;
    vector<shared_ptr<Node>> xWin;
    vector<shared_ptr<Node>> oWin;

    // push head as initial element of queue
    queue.push_back(head);

    while(!queue.empty()) {
        // Iterate through possible actions and add new node to queue for each.
        if(!actions(queue[0]->board).empty() && !winner(queue[0]->board))
        {
            for (int i = 0; i < static_cast<int>(actions(queue[0]->board).size()); i++)
            {
                // Create a new node with new board state from actions and the raw pointer value of queue[0]. 
                shared_ptr<Node> newNode(new Node(result(queue[0]->board, actions(queue[0]->board)[i], queue[0]->playerTurn)));
                newNode->setAction(actions(queue[0]->board)[i]);
                newNode->playerTurn = !queue[0]->playerTurn;
                newNode->parent = queue[0];
                // add the new node to the queue
                queue.push_back(newNode);
                // pop the first element after using it
            }
            //displayBoard(queue[0]->board);
            //printQueue(actions(queue[0]->board));
            //cout << '\n';

            queue.erase(queue.begin());
        }
        else {
            //displayBoard(queue[0]->board);
            int value = utility(queue[0]->board);
            queue[0]->setValue(value);

            if(player && value == 1) {
                return findPath(queue[0], head);
            }
            else if(!player && value == -1) {
                return findPath(queue[0], head);
            }
            else {
                // if no optimal winning solution is found stack other options
                if(value == 0) {
                    draw.push_back(queue[0]);
                }
                else if(value == 1) {
                    xWin.push_back(queue[0]);
                }
                else if(value == -1) {
                    oWin.push_back(queue[0]);
                }
            }

            queue.erase(queue.begin());
        }

    }
    cout << "Exited while" << endl;
    if(!draw.empty()) {
        return findPath(draw.back(), head);
    }
    else {
        if(player) {
            return findPath(oWin.back(), head);
        }
        else {
            return findPath(xWin.back(), head);
        }
    }
}

/*
 Process: takes a node and returns the child with the best move
 Input: 
    head: node to be expanded
    player: players turn to move (X or O)
 Output: pointer to child node.
*/
shared_ptr<Node> aiMove(shared_ptr<Node> head, bool player)
{
    cout << "aiMove func" << endl;
    return minimax(head, player);
}

shared_ptr<Node> playerMove(const shared_ptr<Node>& head, int gameBoard[], bool player) {
    shared_ptr<Node> newNode(new Node(gameBoard));
    newNode->playerTurn = !player;
    return newNode;
}
