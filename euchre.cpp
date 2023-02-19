// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <iostream>
#include "Card.h"
#include "Pack.h"
#include "Player.h"
#include "euchre.h"
#include <cassert>
#include <vector>
#include <fstream>

using namespace std;


//game adt
class Game {

public:

Game(Player &p1, Player &p2, Player &p3, Player &p4, Pack pack_input, int winpts){


 points2win = winpts;
 pack = pack_input;

 players.push_back(&p1);
 players.push_back(&p2);
 players.push_back(&p3);
 players.push_back(&p4);

 p1pts = 0;
 p2pts = 0;
 p3pts = 0;
 p4pts = 0;

}




private:

vector <Player*> players;
Pack pack;
int points2win; //maybe..?

int p1pts;
int p2pts;
int p3pts;
int p4pts;

};










int main(int argc, char **argv) {
  
if(argc != 12){
    cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
     << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
     << "NAME4 TYPE4" << endl;
  }
// check for exactly 12 arguments in command line



int point_2win = stoi(argv[3]);

if(1 < point_2win || point_2win > 100){
    cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
     << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
     << "NAME4 TYPE4" << endl;
  }
//check for points to win being between 1 and 100 inclusive



string shuffleArg = argv[2];

if(shuffleArg != "shuffle" || "noshuffle"){
    cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
     << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
     << "NAME4 TYPE4" << endl;
  }
//check for shuffle argument being either shuffle or noshuffle



//player stuff time
//a is the name, b is the type
string player1a = argv[4];
string player1b = argv[5];

string player2a = argv[6];
string player2b = argv[7];

string player3a = argv[8];
string player3b = argv[9];

string player4a = argv[10];
string player4b = argv[11];

//check for player types being only either simple of human
  if(player1b != "simple" || "human"){
    cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
     << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
     << "NAME4 TYPE4" << endl;
  }
  if(player2b != "simple" || "human"){
    cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
     << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
     << "NAME4 TYPE4" << endl;
  }
  if(player3b != "simple" || "human"){
    cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
     << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
     << "NAME4 TYPE4" << endl;
  }
  if(player4b != "simple" || "human"){
    cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
     << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
     << "NAME4 TYPE4" << endl;
  }


//ok put pack filename into an istream
string pack_filename = argv[1];


ifstream packfile(pack_filename);


if(packfile.is_open() == 0){
  cout << "Error opening " << pack_filename << endl;
}
//if there's problem openeing the pack 

Pack pack(packfile);//this is def right it just like isn't
//becasue the filename has to be done with an istream but idk
//how to do that yet but this is 100% the right syntax



  if(argv[2] == "shuffle"){

    pack.shuffle();

  }

  Player &p1 = *Player_factory(player1a, player1b);
  Player &p2 = *Player_factory(player2a, player2b);
  Player &p3 = *Player_factory(player3a, player3b);
  Player &p4 = *Player_factory(player4a, player4b);










}
