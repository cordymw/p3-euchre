// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <iostream>
#include <fstream>
#include "euchre.h"

using namespace std;

int main(int argc, char **argv) 
{
  // perform initial checks
  if (
      // check 12 args
      argc != 12 || 

      // check points to win is between 1-100
      (atoi(argv[3]) < 0 || atoi(argv[3]) > 100) ||

      // check shuffle arg is "shuffle" or "noshuffle"
      !(argv[2] == "shuffle" || argv[2] == "noshuffle") ||

      // check each player type is either "Simple" or "Human"
      (
        !(argv[5] == "Simple" || argv[5] == "Human") ||
        !(argv[7] == "Simple" || argv[7] == "Human") ||
        !(argv[9] == "Simple" || argv[9] == "Human") ||
        !(argv[11] == "Simple" || argv[11] == "Human")
      )
    )
  {
    cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
     << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
     << "NAME4 TYPE4" << endl;
    
    return 1;
  }

  ifstream inFile;
  inFile.open(argv[1]);

  if (!inFile.is_open()) 
  {
    cout << "Error opening " << argv[1] << endl;
    return 1;
  }


}

void Game::play_game()
{
  set_cards();
  while (t1_pts < pt_target && t2_pts < pt_target)
  {
    play_hand();
  }
}

void Game::play_hand()
{
  const int NUM_TRICKS = 5;
  int winning_team;
  deal();
  set_up_card();
  set_leader();

  play_round_1();

  for (int trick = 0; trick < NUM_TRICKS; trick++)
  {
    play_trick();
  }
  determine_winning_team(winning_team);
  add_points(winning_team);
}

void Game::deal()
{

}