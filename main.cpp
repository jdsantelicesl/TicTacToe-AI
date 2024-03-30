#include "game.cpp"
#include "display.cpp"
using namespace std;
#define SIZE 9
// Version: 0.0.0
// X Always starts first
// Unless you find a way for it to alternate

// TODO: - Input Validation
//       - Making sure that user cannot enter a used up space

int main(){
    int board[SIZE] = {};

    // Display Inital Board
    displayBoard(board);

    // Main Game Loop
    do{    
        getInput(startingPlayer(), board);
        displayBoard(board);
    }while(!winner(board));   
    
    // Display Winner
    cout << "The winner is " << winner(board);

}

