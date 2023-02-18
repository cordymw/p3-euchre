// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <iostream>
#include "Card.h"
#include "Pack.h"
#include "Player.h"
#include "euchre.h"

using namespace std;



int main(int argc, char **argv) {
  
  if(1 == 2){//if there's an error using command line arguments
    cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
     << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
     << "NAME4 TYPE4" << endl;
  }

// check for exactly 12 arguments in command line
//check for points to win being between 1 and 100 inclusive
//check for shuffle argument being either shuffle or noshuffle
//check for player types being only either simple of human

if(1==2){//if there's problem openeing the pack
  cout << "Error opening " << pack_filename << endl;
}







}
