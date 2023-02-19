// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <iostream>
#include "Card.h"
#include "Pack.h"
#include "Player.h"

using namespace std;



class Game {

public:

Game(Player &p1, Player &p2, Player &p3, Player &p4, Pack pack, int winpts);







private:

vector <Player*> players;
Pack pack;
int points2win; //maybe..?

int p1pts;
int p2pts;
int p3pts;
int p4pts;

};

