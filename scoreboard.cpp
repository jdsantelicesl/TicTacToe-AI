#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "game.cpp"
using namespace std;


int scoreboard() 
{
  //---------------------------
  //-----SAMPLE SCOREBOARD-----
  //---------------------------
  int playerXTotalWins = 3,
      playerOTotalWins = 5,
      totalTies = 2;
  //---------------------------
  //---------------------------


  // Vectors to store points for the duration of one game
  vector<string> playerXPoints = {"Player X Points:"},
                  playerOPoints = {"Player O Points:"},
                  tiePoints = {"Ties:"};

  // Records points into vectors
  // ----(switch to bool values)----
  for(int num = 0; num < playerXTotalWins; num++)
    playerXPoints.push_back("|");
  for(int num = 0; num < playerOTotalWins; num++)
    playerOPoints.push_back("|");
  for(int num = 0; num < totalTies; num++)
    tiePoints.push_back("|");



  // Creates output and input stream objects for files
  ofstream ScoreBoardWrite;
  ifstream ScoreBoardRead;


  // Opens and creates score board file
  ScoreBoardWrite.open("ScoreFile.txt");

  // Writes points vectors to score board file
  for(auto el = 0; el < playerXPoints.size(); el++)
    ScoreBoardWrite << playerXPoints[el];
  ScoreBoardWrite << endl;

  for(auto el = 0; el < playerOPoints.size(); el++)
    ScoreBoardWrite << playerOPoints[el];
  ScoreBoardWrite << endl;

  for(auto el = 0; el < tiePoints.size(); el++)
    ScoreBoardWrite << tiePoints[el];
  ScoreBoardWrite << endl;

  // Close file
  ScoreBoardWrite.close();

  //------------------------------------
  // This bottom section is called when the game is over
  // ----------(when user quits game)-----------
  //------------------------------------


  // Opens score board file
  ScoreBoardRead.open("ScoreFile.txt");

  // Reads wins from score board file by line
  string lineOne,
         lineTwo,
         lineThree;
  getline(ScoreBoardRead, lineOne);
  getline(ScoreBoardRead, lineTwo);
  getline(ScoreBoardRead, lineThree);

  // Records amount of wins from each line into totals
  int XTotalWins = lineOne.length(),
      OTotalWins = lineTwo.length(),
      AllTies = lineThree.length();

  // Displays amount of wins and ties
  cout << "Player X won " << XTotalWins - 16 << " times" << endl; // Subtract characters for first element
  cout << "Player O won " << OTotalWins - 16 << " times" << endl;
  cout << "You tied " << AllTies - 5 << " times" << endl;
  // Close file
  ScoreBoardRead.close();

  return 0;
}
