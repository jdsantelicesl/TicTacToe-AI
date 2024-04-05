#include <iostream>
#include "game.cpp"
#include "display.cpp"
using namespace std;
#define SIZE 9
// Version: 0.0.2
// User picks starting symbol

int main()
{
    int board[SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    bool player = startingPlayer();
    bool cont = true;

    while (!winner(board))
    {
        displayBoard(board);
        getInput(player, board);
        player = getPlayer(player);
    }

    cout << "Game over!" << endl;
    displayBoard(board);

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
        cout << "The game ended in a draw." << endl;
    }

    cout << "Thank you for playing" << endl;

    return 0;
}
