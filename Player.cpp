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

    if(round == 1){
      

      for(int i = 0; i < hand.size(); ++i){
        if(hand[i].get_suit() == upcard.get_suit()){
          if(hand[i].is_face_or_ace() == 1){
            ++count;
          }
        }
        if(hand[i].is_left_bower(upcard.get_suit()) == 1){
          ++count;
        }
      }


      if(count >= 2){
        order_up_suit = upcard.get_suit();
        return 1;
      }


    }




    if(round == 2){
      

    if(upcard.get_suit() == 0){
      
        Suit good = CLUBS;

    for(int i = 0; i < hand.size(); ++i){
      

      if(hand[i].get_suit() == 2){
        if(hand[i].is_face_or_ace() == 1){
          ++count;
        }
      }
        if(hand[i].is_left_bower(CLUBS)){
          ++count;
        }
      }
       if(count >=1){
        order_up_suit = good;
        return 1;
        }}



      if(upcard.get_suit() == 1){
        
        Suit good = DIAMONDS;

        for(int i = 0; i < hand.size(); ++i){


        if(hand[i].get_suit() == 3){
        if(hand[i].is_face_or_ace() == 1){
          ++count;
        }
      }
        if(hand[i].is_left_bower(DIAMONDS)){
          ++count;
        }
      }
       if(count >=1){
        order_up_suit = good;
        return 1;
        }}



      if(upcard.get_suit() == 2){

        Suit good = SPADES;

        for(int i = 0; i < hand.size(); ++i){
          

        if(hand[i].get_suit() == 0){
        if(hand[i].is_face_or_ace() == 1){
          ++count;
        }
      }
        if(hand[i].is_left_bower(SPADES)){
          ++count;
        }
      }
      if(count >=1){
        order_up_suit = good;
        return 1;
        }}



      if(upcard.get_suit() == 3){
        
        Suit good = HEARTS;
        
        for(int i = 0; i < hand.size(); ++i){


        if(hand[i].get_suit() == 1){
        if(hand[i].is_face_or_ace() == 1){
          ++count;
        }
      }
        if(hand[i].is_left_bower(HEARTS)){
          ++count;

        }
      }
      if(count >=1){
        order_up_suit = good;
        return 1;
      }}

     

      if(is_dealer == 1){
      order_up_suit = upcard.get_suit();
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
    int minrank = 12;
    //if make trump = true but idk how to do that
     hand.push_back(upcard);

    for(int i= 0; i < hand.size(); ++i){

      if(hand[i].get_suit() != upcard.get_suit()){

        if(hand[i].get_rank() < minrank){

          minrank = hand[i].get_rank();
          index = i;
        }
      }

    }

  int trump = 0;
  for(int i= 0; i < hand.size(); ++i){

    if(hand[i].get_suit() == upcard.get_suit()){
      ++trump;
    }
  }

  if(trump == hand.size()){
    index = 0;
    minrank = 12;

    for(int i= 0; i < hand.size(); ++i){

      if(hand[i].get_rank() < minrank){
        minrank = hand[i].get_rank();
        index = i;
      }
    }
  }
  
    hand.erase(hand.begin()+index);

    }

  
  //REQUIRES Player has at least one card
  //EFFECTS  Leads one Card from Player's hand according to their strategy
  //  "Lead" means to play the first Card in a trick.  The card
  //  is removed the player's hand.
  Card lead_card(Suit trump){
    assert(hand.size() >= 1);

  int index = 0;
  int maxrank = 0;

   for(int i= 0; i < hand.size(); ++i){

      if(hand[i].get_suit() != trump){

        if(hand[i].get_rank() > maxrank){

          maxrank = hand[i].get_rank();
          index = i;
        }
      }

    }




  int count = 0;
  for(int i= 0; i < hand.size(); ++i){

    if(hand[i].is_trump(trump) == 1){
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



    //just in case wither of them is a bower here's what we gotta do

      if(hand[i].is_left_bower(trump) == 1){
        break;
      }

      if(hand[i].is_right_bower(trump) == 1){
        break;
      }
    }
  
  for(int i= 0; i < hand.size(); ++i){

    if(hand[i].is_left_bower(trump) == 1){

          index = i;
          break;
        }
    }

  for(int i= 0; i < hand.size(); ++i){
    
    if(hand[i].is_right_bower(trump) == 1){

          index = i;
          break;
        }
    }
  }
  
  Card returned = hand[index];
  hand.erase(hand.begin() + index);
  return returned;

}

  //REQUIRES Player has at least one card
  //EFFECTS  Plays one Card from Player's hand according to their strategy.
  //  The card is removed from the player's hand.
  Card play_card(const Card &led_card, Suit trump){
    assert(hand.size() >= 1);

    int index = 0;
    int maxrank = 0;
    int minrank = 12;

    //follow suit code
    for(int i = 0; i < hand.size(); ++i){

      if(hand[i].get_suit() == led_card.get_suit()){

        if(hand[i].get_rank() > maxrank){

          maxrank = hand[i].get_rank();
          index = i;
        }
      }
    }

    //bower check
    for(int i = 0; i < hand.size(); ++i){

      if((led_card.get_suit() == trump) && (hand[i].get_suit() == led_card.get_suit())){

        if(hand[i].is_left_bower(trump) == 1){

          index = i;
        }
      }
    }

    for(int i = 0; i < hand.size(); ++i){

      if((led_card.get_suit() == trump) && (hand[i].get_suit() == led_card.get_suit())){

        if(hand[i].is_right_bower(trump) == 1){

          index = i;
        }
      }
    }

    //cannot follow suit code
    int count = 0;

    for(int i = 0; i < hand.size(); ++i){
      if(led_card.get_suit() != hand[i].get_suit()){
        ++count;
      }
    }

    if(count == hand.size()){

      for(int i = 0; i < hand.size(); ++i){

        if(hand[i].get_rank() < minrank){

          minrank = hand[i].get_rank();
          index = i;

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

    add_card(upcard);

    print_hand();



    cout << "Discard upcard: [-1]\n";
    cout << "Human player " << name << ", please select a card to discard:\n";

    int index;
    cin >> index;

    int upin = 0;
    if(index == -1){
      
      for(int i = 0; i < hand.size(); ++i){

        if(hand[i] == upcard){
          upin = i;
        }
      }
      hand.erase(hand.begin() + upin);

    }
    else{
      hand.erase(hand.begin() + index);
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
