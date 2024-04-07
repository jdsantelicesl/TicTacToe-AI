#include <iostream>
#include <vector>

#include "display.cpp"
#include "game.cpp"
#include "ai.cpp"

using namespace std;

void displayChildren(Node *head) {
    for(int i = 0; i < static_cast<int>(head->children.size()); i++) {
        cout << "Children board " << i << endl;
        displayBoard(head->children[i]->board);
        cout << "\n";
    }
}

int main()
{
    int board[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    bool player = true;
    Node *head = new Node(board);

    vector<int> actions = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    createChildren(actions, head, player);

    minimax(head);

    displayBoard(board);

    while(!winner(board)) {
        getInput(player, board);
        head = playerMove(head, board);
        cout << "\nYou made your move" << endl;
        displayBoard(board);
        if(winner(board)) {
            break;
        }


        cout << "\nAi to move..." << endl;
        head = aiMove(head, !player);
        
        if(!player) {
            board[head->action] = 1;
        }
        else {
            board[head->action] = -1;
        }

        displayBoard(board);
        cout << '\n';
    }

    if(winner(board) == 'X') {
        cout << "X wins!" << endl;
    }
    if(winner(board) == 'D') {
        cout << "O wins!" << endl;
    }
    else {
        cout << "Game end in a draw!" << endl;
    }

    cout << "Thank you for playing" << endl;

    return 0;
}