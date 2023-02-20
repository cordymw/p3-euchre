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

  // set up game pack
  Pack game_pack(inFile);
  inFile.close();

  // set up players
  vector<Player*> players;
  for (int i = 4; i < 12; i += 2)
  {
    int j = i + 1;
    players.push_back(Player_factory(argv[i], argv[j]));
  }

  // set up shuffle
  bool shuffle = 0;
  if (argv[2] == "shuffle") 
  {
    shuffle = 1;
  }

  Game game(game_pack, shuffle, atoi(argv[3]), players);
  game.play_game();

  return 0;
}

Game::Game(){} 

Game::Game(Pack c, bool s, int pts, vector<Player*> p) 
{
  pack = c;
  shuffle = s;
  pt_target = pts;
  players = p;
  dealer = players[0];
  leader = dealer + 1;
  t1_pts = 0;
  t2_pts = 0;
}

void Game::play_game()
{
  while (t1_pts < pt_target && t2_pts < pt_target)
  {
    play_hand();
  }
}

void Game::play_hand()
{
  const int NUM_TRICKS = 5;
  int winning_team;

  if (shuffle == 1)
  {
    pack.shuffle();
  }

  deal();

  set_up_card();
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
  int count_order[] = {3, 2, 3, 2, 2, 3, 2, 3};
  int player_order[8];
  int start_element = leader - dealer;

  for (int i = 0; i < 8; i++)
  {
    player_order[i] = start_element;
    start_element++;
    if (start_element > 3)
    {
      start_element = 0;
    }
  }

  for (int i = 0; i < 8; i++)
  {
    for (int count = 0; count < count_order[i]; count++)
    {
      players[player_order[i]]->add_card(pack.deal_one());
    }
  }
}

void Game::set_up_card()
{
  upcard = pack.deal_one();
}

void Game::play_round_1()
{
  bool trump_made = 0;
  
  int i = 0;
  while (trump_made = 0 && i < 4)
  {
   
  }
}