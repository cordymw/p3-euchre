// Project UID 1d9f47bfc76643019cfbf037641defe1
#include "Pack.h"
#include <cassert>
#include <iostream>

using namespace std;

Pack::Pack()
{
  int i = 0;
  for (int s = 0; s < 4; s++)
  {
    for (int r = 7; r < 13; r++)
    {
      cards[i] = Card((Rank)r, (Suit)s);
      i++;
    }
  }
  next = 0;
}

Pack::Pack(std::istream& pack_input)
{
  string rank;
  string suit;
  string junk;
  int i = 0;

  while (pack_input >> rank >> junk >> suit)
  {
    cards[i] = Card(string_to_rank(rank), string_to_suit(suit));
    i++;
  }
  next = 0;
}

Card Pack::deal_one()
{
  Card *nextCard = &cards[next];
  next++;
  return *nextCard;
}

void Pack::reset()
{
  next = 0;
}

void Pack::shuffle()
{
  
}

bool Pack::empty() const
{
  return next == 24;
}
