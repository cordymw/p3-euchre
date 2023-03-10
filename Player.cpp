//Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Player.h"
#include <cassert>
#include <iostream>
#include <array>
#include <vector>
#include "Card.h"
#include <algorithm>

using namespace std;


class Simple : public Player{

  public:

  //constructor time baybee
  Simple(const string name_in){
    name= name_in;
  }

    //EFFECTS returns player's name
  const std::string & get_name() const{
    return name;
  }

  //REQUIRES player has less than MAX_HAND_SIZE cards
  //EFFECTS  adds Card c to Player's hand
  void add_card(const Card &c){

    assert(hand.size() < MAX_HAND_SIZE);

    hand.push_back(c);

  }


  //REQUIRES round is 1 or 2
  //MODIFIES order_up_suit
  //EFFECTS If Player wishes to order up a trump suit then return true and
  //  change order_up_suit to desired suit.  If Player wishes to pass, then do
  //  not modify order_up_suit and return false.
  bool make_trump(const Card &upcard, bool is_dealer,
                          int round, Suit &order_up_suit) const{

    assert(round == 1 || 2);

    int count = 0;

    Suit good = upcard.get_suit();
    Suit next = Suit_next(good);

    if(round == 1){
      

      for(int i = 0; i < hand.size(); ++i){
        if(((hand[i].get_suit() == upcard.get_suit()) && 
        (hand[i].is_face_or_ace())) || 
        (hand[i].is_left_bower(upcard.get_suit()))){

            ++count;
      }
    }

      if(count >= 2){
        order_up_suit = upcard.get_suit();
        return 1;
      }


    }


    //good is trump suit
    //next is same color

    if(round == 2){


    for(int i = 0; i < hand.size(); ++i){
      

      if((hand[i].get_suit() == next) && hand[i].is_face_or_ace()){
        
          ++count;
      }
      if(hand[i].is_left_bower(good)){
          ++count;
        }
      }

    if(count >=1){

      order_up_suit = next;
      return 1;
      }


      if(is_dealer == 1){

      order_up_suit = good;
      return 1;
      }
    }

  return 0;
  }

  //REQUIRES Player has at least one card
  //EFFECTS  Player adds one card to hand and removes one card from hand.
  void add_and_discard(const Card &upcard){
    assert(hand.size() >= 1);

    int index = 0;
     hand.push_back(upcard);

//call card less to find min card
Card low = hand[index];

    for(int i= 0; i < hand.size(); ++i){

      if(Card_less(hand[i], low, upcard.get_suit()) == 1){

        low = hand[i];
        index = i;

      }
    }
  
    hand.erase(hand.begin() + index);

    }

  
  //REQUIRES Player has at least one card
  //EFFECTS  Leads one Card from Player's hand according to their strategy
  //  "Lead" means to play the first Card in a trick.  The card
  //  is removed the player's hand.


  //strat:
  // When a Simple Player leads a trick, they play the 
  // highest non-trump card in their hand. If they have only 
  // trump cards, they play the highest trump card in their hand.

  Card lead_card(Suit trump){
    assert(hand.size() >= 1);

  int index;
  int maxrank = 0;


  //highest non-trump
   for(int i= 0; i < hand.size(); ++i){

      if(hand[i].get_suit() != trump){

        if(hand[i].is_left_bower(trump) == 1){

          maxrank = maxrank;

        }

        else if(hand[i].get_rank() > maxrank){

          maxrank = hand[i].get_rank();
          index = i;
        }

        else if((hand[i].get_rank() == maxrank) && 
        (hand[i].get_suit() > hand[index].get_suit())){
          maxrank = hand[i].get_rank();
          index = i;
        }
      }

    }




 //only trump 
  int count = 0;
  for(int i= 0; i < hand.size(); ++i){

    if(hand[i].is_trump(trump) == 1){
      ++count;
    }

    //since left bower is considered trump
    //suit, add it to the count of
    //"if only trump cards"
    if(hand[i].is_left_bower(trump)){
      ++count;
    }
  }


  if(count == hand.size()){
    index = 0;
    maxrank = 0;

    for(int i= 0; i < hand.size(); ++i){

      if(hand[i].get_rank() > maxrank){
        maxrank = hand[i].get_rank();
        index = i;
      }

    }
  

  
  //just in case either of them is a bower here's what we gotta do

  //left bower
  for(int i= 0; i < hand.size(); ++i){

    if(hand[i].is_left_bower(trump) == 1){

          index = i;
        }
    }

  //right bower
  for(int i= 0; i < hand.size(); ++i){
    
    if(hand[i].is_right_bower(trump) == 1){

          index = i;
        }
    }
  

  //end of if only trump section
  }
  

  //make a copy of card to play, delete real card, return copy
  Card returned = hand[index];

  hand.erase(hand.begin() + index);

  return returned;

}

  //REQUIRES Player has at least one card
  //EFFECTS  Plays one Card from Player's hand according to their strategy.
  //  The card is removed from the player's hand.



  //strat:
  // If a Simple Player can follow suit, they play the 
  // highest card that follows suit. Otherwise, they play 
  // the lowest card in their hand.

  Card play_card(const Card &led_card, Suit trump){
    assert(hand.size() >= 1);

    int index = 0;
    int maxrank = 0;
    int minrank = 12;
    bool followed = 0;


    //follow suit code
    for(int i = 0; i < hand.size(); ++i){

      if((hand[i].get_rank() >= maxrank) && 
      (hand[i].get_suit() == led_card.get_suit()) && 
      (hand[i].is_left_bower(trump) == 0)){

        index = i;
        maxrank = hand[i].get_rank();
        followed = 1;
      }
    }

    //if led suit is also trump
    if((led_card.get_suit() == trump) || led_card.is_left_bower(trump)){

      //general cards
      for(int i = 0; i < hand.size(); ++i){

        if((hand[i].get_suit() == trump) && (hand[i].get_rank() > maxrank)){

          index = i;
          maxrank = hand[i].get_rank();
          followed = 1;
        }

      }

      //check for left bower
      for(int i = 0; i < hand.size(); ++i){

        if(hand[i].is_left_bower(trump) == 1){
          index = i;
          followed = 1;
        }
      }

      //check for right bower
      for(int i = 0; i < hand.size(); ++i){

        if(hand[i].is_right_bower(trump) == 1){
          index = i;
          followed = 1;
        }
      }
    }



  //if player can't follow suit


  int count1 = 0;
  //if the led suit isn't the trump suit
  if((led_card.get_suit() != trump) && !followed){




    for(int i = 0; i < hand.size(); ++i){

      if((hand[i].get_suit() != led_card.get_suit()) || hand[i].is_left_bower(trump)){

        ++count1;
      }

    }


  //if all of the cards in players hand
  //are cards not same suit as led suit,
  //AND aren't trump,
  //then find the minimum rank

    for(int i = 0; i < hand.size(); ++i){

      if((count1 == hand.size()) && 
      
      (hand[i].get_suit() != trump) && 

      (hand[i].get_rank() <= minrank) && 

      (hand[i].is_left_bower(trump) == 0)){


        minrank = hand[i].get_rank();
        index = i;
      }
    
  }


  int count2 = 0;
  for(int i = 0; i < hand.size(); ++i){

    if((hand[i].get_suit() == trump) || (hand[i].is_left_bower(trump))){

      ++count2;
    }
  }

  //if all cards in hand ARE trump,
  //and led suit isn't trump



    for(int i = 0; i < hand.size(); ++i){

      if(
        (count2 == hand.size()) &&

        (hand[i].get_rank() <= minrank) && 
      
        (hand[i].get_rank() != 9)){

        index = i;
        minrank = hand[i].get_rank();
      }
    }
  }


maxrank = 0;
minrank = 12;
//if led suit IS trump (makes things a lot easier)
if((led_card.get_suit() == trump) || led_card.is_left_bower(trump)){



  for(int i = 0; i < hand.size(); ++i){

    if((hand[i].get_rank() > maxrank) && (hand[i].get_suit() == trump)){
      index = i;
      maxrank = hand[i].get_rank();
    }

  }

  int count3 = 0;
  for(int i = 0; i < hand.size(); ++i){

    if(hand[i].get_suit() != trump){

      ++count3;
    }

    if(hand[i].is_left_bower(trump) == 1){

      count3--;
    }
  }

  //bower check
  for(int i = 0; i < hand.size(); ++i){
    if(hand[i].is_left_bower(trump)){
      index = i;
      maxrank = 13;
    }

  }

  for(int i = 0; i < hand.size(); ++i){
    if(hand[i].is_right_bower(trump)){
      index = i;
      maxrank = 14;
    }

  }
  //if all of the cards in players hand
  //aren't trump/led suit
  minrank = 12;

    for(int i = 0; i < hand.size(); ++i){

      if((count3 == hand.size()) &&

        (hand[i].get_rank() < minrank)){

        index = i;
        minrank = hand[i].get_rank();
      }

      if((count3 == hand.size()) &&

        (hand[i].get_rank() == minrank) && 

        (hand[i].get_suit() < hand[index].get_suit())){

        index = i;
        minrank = hand[i].get_rank();
      }
    }
}


    //make a copy of card to play, delete real card, return copy
    Card copy = hand[index];

    hand.erase(hand.begin() + index);

    return copy;
  }



  private:

 string name;
 vector <Card> hand;
};








class Human : public Player{

  public:

  //constructor time baybee
  Human(const string name_in){
    name= name_in;
  }
        //EFFECTS returns player's name
  const std::string & get_name() const{
    return name;
  }

  //REQUIRES player has less than MAX_HAND_SIZE cards
  //EFFECTS  adds Card c to Player's hand
  void add_card(const Card &c){

  //assert(hand.size() < MAX_HAND_SIZE);

  hand.push_back(c);

  sort(hand.begin(), hand.end());
  }


  //REQUIRES round is 1 or 2
  //MODIFIES order_up_suit
  //EFFECTS If Player wishes to order up a trump suit then return true and
  //  change order_up_suit to desired suit.  If Player wishes to pass, then do
  //  not modify order_up_suit and return false.
  bool make_trump(const Card &upcard, bool is_dealer,
                          int round, Suit &order_up_suit) const{
    assert(round == 1 || 2);


  

  print_hand();


  
  
  cout << "Human player " << name << ", please enter a suit, or \"pass\":\n";
  string decision;
  cin >> decision;

if (decision != "pass") {
  order_up_suit = string_to_suit(decision);
  return 1;
}

return 0;

  }

  //REQUIRES Player has at least one card
  //EFFECTS  Player adds one card to hand and removes one card from hand.
  void add_and_discard(const Card &upcard){
    assert(hand.size() >= 1);


    print_hand();


    cout << "Discard upcard: [-1]\n";
    cout << "Human player " << name << ", please select a card to discard:\n";

    int index;
    cin >> index;



    if(index != -1){
      
      hand.erase(hand.begin() + index);

      add_card(upcard);
    }


  }
  //REQUIRES Player has at least one card
  //EFFECTS  Leads one Card from Player's hand according to their strategy
  //  "Lead" means to play the first Card in a trick.  The card
  //  is removed the player's hand.
  Card lead_card(Suit trump){
    assert(hand.size() >= 1);

    
    print_hand();


    cout << "Human player " << name << ", please select a card:\n";

    int index;
    cin >> index;

    Card returned = hand[index];
    hand.erase(hand.begin() + index);
    return returned;
  }

  //REQUIRES Player has at least one card
  //EFFECTS  Plays one Card from Player's hand according to their strategy.
  //  The card is removed from the player's hand.
  Card play_card(const Card &led_card, Suit trump){
  assert(hand.size() >= 1);

  

  print_hand();



  cout << "Human player " << name << ", please select a card:\n";

  int index;
  cin >> index;

  Card returned = hand[index];
  hand.erase(hand.begin() + index);
  return returned;
  }

  private:

  string name;
  vector <Card> hand;
  
  void print_hand() const {
  for (size_t i=0; i < hand.size(); ++i)
    cout << "Human player " << name << "'s hand: "
         << "[" << i << "] " << hand[i] << "\n";}

};

//EFFECTS: Returns a pointer to a player with the given name and strategy
//To create an object that won't go out of scope when the function returns,
//use "return new Simple(name)" or "return new Human(name)"
//Don't forget to call "delete" on each Player* after the game is over
Player * Player_factory(const std::string &name, const std::string &strategy) {

   if (strategy == "Simple") {
    return new Simple(name);
   }

    if (strategy == "Human") {
    return new Human(name);
  }
   
   return 0;
}


//EFFECTS: Prints player's name to os
std::ostream & operator<<(std::ostream &os, const Player &p) {
  
os << p.get_name();
return os;

}


//3456789022345678903234567890423456789052345678906234567890723456789082345678909234567890
