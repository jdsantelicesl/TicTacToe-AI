#include "gamemode.cpp"
// Version: 0.1.1
// User picks gamemode, true => PvP, false => PvAI
// Included Board with Coords
// To Do: Fix Scoreboard
int main()
{
    bool play = true;

    // Display the coords
    displayBoardCoords();
    
    while (play) {
        bool gamemode = gameMode();

        if (gamemode)
            playerVsPlayer();
        else         
            playerVsAi();

        play = playAgain();
    }
    cout << "Thank you for playing!" << endl;
    create_scoreboard(X_points, O_points, tie_points);
    display_scoreboard();
}
