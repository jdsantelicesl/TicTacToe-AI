#include "gamemode.cpp"
// Version: 0.0.3
// User picks gamemode, true => PvP, false => PvAI
// Game loops until terminates by user
int main()
{
    bool play = true;

    while (play) {
        bool gamemode = gameMode();

        if (gamemode)
            playerVsPlayer();
        else         
            playerVsAi();

        play = playAgain();
    }

    cout << "Thank you for playing!" << endl;

}