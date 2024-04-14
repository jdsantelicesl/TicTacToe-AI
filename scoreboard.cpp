#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int X_points=0, O_points=0, tie_points=0;

/*
Process : Creates a scoreboard array and writes the array into a file
Input   : X_points, O_points, and tie_points
Output  : None.
*/
void create_scoreboard(int X_points,int O_points,int tie_points) 
{
  //creates score array
  string scores[3][2] ={{"Player X Points:",to_string(X_points)},
                       {"Player O Points: ",to_string(O_points)},
                       {"Ties",to_string(tie_points)}};

  // Creates output stream object for the file
  ofstream ScoreBoardWrite;

  // Opens and creates score board file
  ScoreBoardWrite.open("ScoreFile.txt");

  // Writes score array to score board file
  for(auto row = 0; row < 3; row++)
    {
    for(auto col = 0; col < 2; col++)
      ScoreBoardWrite << scores[row][col];
    ScoreBoardWrite << endl;
    }

  // Close file
  ScoreBoardWrite.close();

}

/*
Process : Adds a point to the respective player
Input   : char winner
Output  : None.
*/
void add_point(char winner)
{
  if (winner=='X')
    X_points++;
  else if (winner=='O')
    O_points++;
  else
  tie_points++;
}


/*
Process : reads from scoreboard file and displays it
Input   : None.
Output  : None.
*/
void display_scoreboard()
{
   // Creates input stream objects for files
  ifstream ScoreBoardRead;
  // Opens score board file
  ScoreBoardRead.open("ScoreFile.txt");

  // Reads wins from score board file by line
  string lineOne,
         lineTwo,
         lineThree;
  getline(ScoreBoardRead, lineOne);
  getline(ScoreBoardRead, lineTwo);
  getline(ScoreBoardRead, lineThree);

  //prints wins line by line
 cout<<lineOne<<endl
     <<lineTwo<<endl
     <<lineThree<<endl;

  //close file
  ScoreBoardRead.close();
}
