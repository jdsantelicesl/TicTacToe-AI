#include <iostream>
#include <string>
#include "game.cpp"
#include "display.cpp"
#include "ai.cpp"

using namespace std;

#define SIZE 9

// Needs input validation
bool playAgain() {
    string response;
    cout << "Do you want to play again? (yes/no): ";
    cin >> response;
    cout << endl;
    return response == "yes";
}

// Module that asks if user wants to play PvP or PvAI
// Returns value True for PvP, False for PvAI
bool gameMode()
{

    unsigned user_input;

    cout << "Press 1 for Player vs Player\n"
        << "Press 2 for Player vs AI\n"
        << "============================\n"
        << "Enter: ";

    do
    {
        cin >>  user_input;
        if (user_input != 1 && user_input !=2)
        {
            cout << "Please Enter the correct choice: ";
        }

    } while(user_input != 1 && user_input != 2);
        
    return user_input == 1;
}

int playerVsPlayer()
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

// ----------------------------------
// Underneath is Player vs Ai
// ----------------------------------

void displayChildren(Node *head) 
{
    for(int i = 0; i < static_cast<int>(head->children.size()); i++)
     {
        cout << "Children board " << i << endl;
        displayBoard(head->children[i]->board);
        cout << "\n";
    }
}

int playerVsAi()
{
    int board[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    bool player = true;
    Node *head = new Node(board);

    vector<int> actions = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    createChildren(actions, head, player);

    minimax(head);

    displayBoard(board);

    while(!winner(board)) 
    {
        getInput(player, board);
        head = playerMove(head, board);
        cout << "\nYou made your move" << endl;
        displayBoard(board);
        if(winner(board)) 
        {
            break;
        }


        cout << "\nAi to move..." << endl;
        head = aiMove(head, !player);
        
        if(!player) 
        {
            board[head->action] = 1;
        }
        else 
        {
            board[head->action] = -1;
        }

        displayBoard(board);
        cout << '\n';
    }

    if(winner(board) == 'X') 
    {
        cout << "X wins!" << endl;
    }
    else if(winner(board) == 'O') 
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

