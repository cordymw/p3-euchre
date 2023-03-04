// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <cassert>
#include <iostream>
#include <array>
#include "Card.h"

using namespace std;

/////////////// Rank operator implementations - DO NOT CHANGE ///////////////

constexpr const char *const RANK_NAMES[] = {
  "Two",   // TWO
  "Three", // THREE
  "Four",  // FOUR
  "Five",  // FIVE
  "Six",   // SIX
  "Seven", // SEVEN
  "Eight", // EIGHT
  "Nine",  // NINE
  "Ten",   // TEN
  "Jack",  // JACK
  "Queen", // QUEEN
  "King",  // KING
  "Ace"    // ACE
};


//REQUIRES str represents a valid rank ("Two", "Three", ..., "Ace")
Rank string_to_rank(const std::string &str) {
  for(int r = TWO; r <= ACE; ++r) {
    if (str == RANK_NAMES[r]) {
      return static_cast<Rank>(r);
    }
  }
  assert(false); // Input string didn't match any rank
}

//EFFECTS Prints Rank to stream, for example "Two"
std::ostream & operator<<(std::ostream &os, Rank rank) {
  os << RANK_NAMES[rank];
  return os;
}

//EFFECTS Reads a Rank from a stream, for example "Two" -> TWO
std::istream & operator>>(std::istream &is, Rank &rank) {
  string str;
  if(is >> str) {
    rank = string_to_rank(str);
  }
  return is;
}



/////////////// Suit operator implementations - DO NOT CHANGE ///////////////

constexpr const char *const SUIT_NAMES[] = {
  "Spades",   // SPADES
  "Hearts",   // HEARTS
  "Clubs",    // CLUBS
  "Diamonds", // DIAMONDS
};

//REQUIRES str represents a valid suit ("Spades", "Hearts", "Clubs", or "Diamonds")
Suit string_to_suit(const std::string &str) {
  for(int s = SPADES; s <= DIAMONDS; ++s) {
    if (str == SUIT_NAMES[s]) {
      return static_cast<Suit>(s);
    }
  }
  assert(false); // Input string didn't match any suit
}

//EFFECTS Prints Suit to stream, for example "Spades"
std::ostream & operator<<(std::ostream &os, Suit suit) {
  os << SUIT_NAMES[suit];//segfault here for some reason in player public tests?
  return os;
}

//EFFECTS Reads a Suit from a stream, for example "Spades" -> SPADES
std::istream & operator>>(std::istream &is, Suit &suit) {
  string str;
  if (is >> str) {
    suit = string_to_suit(str);
  }
  return is;
}


/////////////// Write your implementation for Card below ///////////////


// NOTE: We HIGHLY recommend you check out the operator overloading
// tutorial in the project spec before implementing
// the following operator overload functions:
//   operator<<
//   operator>>
//   operator<
//   operator<=
//   operator>
//   operator>=
//   operator==
//   operator!=

Card::Card()
{
  suit = SPADES;
  rank = TWO;
}

Card::Card(Rank rank_in, Suit suit_in)
{
  rank = rank_in;
  suit = suit_in;
}

Rank Card::get_rank() const
{
  return rank;
}

Suit Card::get_suit() const
{
  return suit;
}

Suit Card::get_suit(Suit trump) const
{
  if (is_left_bower(trump) == 1)
  {
    return trump;
  }
  else
  {
    return suit;
  }
}

bool Card::is_face_or_ace() const
{
  return rank == ACE ||
         rank == JACK ||
         rank == QUEEN ||
         rank == KING;
}

bool Card::is_right_bower(Suit trump) const
{
  return suit == trump && rank == JACK;
}

bool Card::is_left_bower(Suit trump) const
{
  if (trump == SPADES || trump == CLUBS)
  {
    if (trump == SPADES)
    {
      if (suit == CLUBS && rank == JACK)
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }

    if (trump == CLUBS)
    {
      if (suit == SPADES && rank == JACK)
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }
  }

  if (trump == HEARTS || trump == DIAMONDS)
  {
    if (trump == HEARTS)
    {
      if (suit == DIAMONDS && rank == JACK)
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }

    if (trump == DIAMONDS)
    {
      if (suit == HEARTS && rank == JACK)
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }
  }
  return 0;
}

bool Card::is_trump(Suit trump) const
{
  if (suit == trump)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

std::ostream & operator<<(std::ostream &os, const Card &card){

  Card card1 = card;
  Rank rank = card1.get_rank();
  Suit suit = card1.get_suit();

  return os << rank << " of " << suit;

}

std::istream & operator>>(std::istream &is, Card &card)
{
  string rank;
  string junk;
  string suit;

  is >> rank >> junk >> suit;
  card.rank = string_to_rank(rank);
  card.suit = string_to_suit(suit);
  return is;
}


bool operator<(const Card &lhs, const Card &rhs){

  Card cardLeft= lhs;
  Card cardRight= rhs;

  int cardLeftval= cardLeft.get_rank();
  int cardRightval= cardRight.get_rank();

  if(cardLeftval < cardRightval){
    return 1;
  }
  else{
    return 0;
  }
  
}

bool operator<=(const Card &lhs, const Card &rhs){

  Card cardLeft= lhs;
  Card cardRight= rhs;

  int cardLeftval= cardLeft.get_rank();
  int cardRightval= cardRight.get_rank();

  if(cardLeftval <= cardRightval){
    return 1;
  }
  else{
    return 0;
  }

}

bool operator>(const Card &lhs, const Card &rhs){
  
  Card cardLeft= lhs;
  Card cardRight= rhs;

  int cardLeftval= cardLeft.get_rank();
  int cardRightval= cardRight.get_rank();

  if(cardLeftval > cardRightval){
    return 1;
  }
  else{
    return 0;
  }

}

bool operator>=(const Card &lhs, const Card &rhs){
  
  Card cardLeft= lhs;
  Card cardRight= rhs;

  int cardLeftval= cardLeft.get_rank();
  int cardRightval= cardRight.get_rank();

  if(cardLeftval >= cardRightval){
    return 1;
  }
  else{
    return 0;
  }

}

bool operator==(const Card &lhs, const Card &rhs){
  
  Card cardLeft= lhs;
  Card cardRight= rhs;

  int cardLeftval= cardLeft.get_rank();
  int cardRightval= cardRight.get_rank();

  if(cardLeftval == cardRightval){
    return 1;
  }
  else{
    return 0;
  }
//let it be known that as of 2/9/23 i am NOT considering suit inside operator== and operator !=
//since it wouldn't make sense to have two of the exact same card in a deck, but if need be
//i would:
// add variables     int cardLeftSuit = cardLeft.get_suit()      int cardRightsuit = cardRight.get_suit()
// change the if statement to if(cardLeftval == cardRightval && cardLeftsuit == cardRightsuit)
}

bool operator!=(const Card &lhs, const Card &rhs){
  
  Card cardLeft= lhs;
  Card cardRight= rhs;

  int cardLeftval= cardLeft.get_rank();
  int cardRightval= cardRight.get_rank();

  if(cardLeftval != cardRightval){
    return 1;
  }
  else{
    return 0;
  }
//let it be known that as of 2/9/23 i am NOT considering suit inside operator== and operator !=
//since it wouldn't make sense to have two of the exact same card in a deck, but if need be
//i would:
// add variables     int cardLeftSuit = cardLeft.get_suit()      int cardRightsuit = cardRight.get_suit()
// change the if statement to if(cardLeftval != cardRightval || cardLeftsuit != cardRightsuit)
}

Suit Suit_next(Suit suit){
  
  if(suit == 0){
    return HEARTS;
  }

  if(suit == 1){
    return CLUBS;
  }

  if(suit == 2){
    return DIAMONDS;
  }
  
  return SPADES;
}

//EFFECTS Returns true if a is lower value than b.  Uses trump to determine
// order, as described in the spec.
bool Card_less(const Card &a, const Card &b, Suit trump){
  if(b.get_suit() == trump){
    return 1;
  }

  if(a.get_suit() == trump){
    return 0;
  }

  if(a.get_suit() != trump && b.get_suit() != trump){

    if(b.get_rank() > a.get_rank()){
      return 1;
    }
    else{
      return 0;
    }

  }
  return 0;
}

//EFFECTS Returns true if a is lower value than b.  Uses both the trump suit
//  and the suit led to determine order, as described in the spec.
bool Card_less(const Card &a, const Card &b, const Card &led_card, Suit trump){
  //if card b is the led suit and a isnt trump, true
  //if card b is led suit and a is trump, false
  //if card b is trump and card a is trump, if rank b > a, true
  //if neither led suit and neither trump, false since they're both automiatic losers:: implemented in the final return 0

  //i didn't wanna have 4 conditions in 1 if statement because it looked dumb and bad so 
  //my thought process is to return 0 at the end that way if all of the rest of the conditions
  //are unmet for any of the if statements then it just isn't true becaus they're both losers
  Suit ledSuit = led_card.get_suit();

  Rank br = b.get_rank();
  Suit bs = b.get_suit();

  Rank ar = a.get_rank();
  Suit as = a.get_suit();


//diff ranks
if(bs == trump && as != trump){
  return 1;
}

if(bs == ledSuit && as != ledSuit){
  return 1;
}


//same ranks
if(bs == trump && as == trump){
  if(br > ar){
    return 1;
  }
}

if(bs == ledSuit && as == ledSuit){
  if(br > ar){
    return 1;
  }
}



return 0;
//end of card_less
}




