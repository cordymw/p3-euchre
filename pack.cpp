// Project UID 1d9f47bfc76643019cfbf037641defe1
#include "Card.h"
#include "Pack.h"
#include <array>
#include <string>
#include <cassert>
#include <iostream>

using namespace std;

class Pack {
public:
  // EFFECTS: Initializes the Pack to be in the following standard order:
  //          the cards of the lowest suit arranged from lowest rank to
  //          highest rank, followed by the cards of the next lowest suit
  //          in order from lowest to highest rank, and so on.
  // NOTE: The standard order is the same as that in pack.in.
  // NOTE: Do NOT use pack.in in your implementation of this function
  Pack(){
    assert(false);//implement pls
  }

  // REQUIRES: pack_input contains a representation of a Pack in the
  //           format required by the project specification
  // MODIFIES: pack_input
  // EFFECTS: Initializes Pack by reading from pack_input.
  Pack(istream& pack_input){
    assert(false);//implement pls
  }

  // REQUIRES: cards remain in the Pack
  // EFFECTS: Returns the next card in the pack and increments the next index
  Card deal_one(){
    assert(false);//implement pls
  }

  // EFFECTS: Resets next index to first card in the Pack
  void reset(){
    assert(false);//implement pls
  }

  // EFFECTS: Shuffles the Pack and resets the next index. This
  //          performs an in shuffle seven times. See
  //          https://en.wikipedia.org/wiki/In_shuffle.
  void shuffle(){
    assert(false);//implement pls
  }

  // EFFECTS: returns true if there are no more cards left in the pack
  bool empty() const{
    assert(false);//implement pls
  }

private:
  static const int PACK_SIZE = 24;
  std::array<Card, PACK_SIZE> cards;
  int next; //index of next card to be dealt
};