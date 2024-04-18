#include <iostream>
#include <string>
#include "game.cpp"
#include "display.cpp"
#include "ai.cpp"

int main() {
    int board[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    bool player = true;
    shared_ptr<Node> head(new Node(board));
    head->setPlayer(!player);

    cout << "head player: " << head->playerTurn << endl;

    vector<int> actions = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    displayBoard(board);

    while (!winner(board))
    {
        getInput(player, board);
        head = playerMove(head, board, player);
        cout << "\nYou made your move" << endl;
        displayBoard(board);
        if (winner(board))
        {
            break;
        }

        cout << "\nAi to move..." << endl;
        head = aiMove(head, !player);

        if (!player)
        {
            board[head->action] = 1;
        }
        else
        {
            cout << head->action << endl;
            board[head->action] = -1;
        }

        displayBoard(board);
        cout << '\n';
        displayBoard(head->board);
        cout << '\n';
        cout << "current node value: " << head->value << endl;
    }

    if (winner(board) == 'X')
    {
        cout << "X wins!" << endl;
    }
    else if (winner(board) == 'O')
    {
        cout << "O wins!" << endl;
    }
    else
    {
        cout << "Game end in a draw!" << endl;
    }

    cout << "Thank you for playing" << endl;

    return 0;
}