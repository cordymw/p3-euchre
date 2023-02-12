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
  Card half1[PACK_SIZE / 2]; // holds first half of pack
  Card half2[PACK_SIZE / 2]; // holds second half of pack
  const int NUM_SHUFFLES = 7;

  // perform in shuffle 7x
  for (int i = 0; i < NUM_SHUFFLES; i++)
  {
    // split cards
    for (int j = 0; j < PACK_SIZE / 2; j++)
    {
      half1[j] = cards[j];
    }
    for (int j = PACK_SIZE / 2; j < PACK_SIZE; j++)
    {
      half2[j] = cards[j];
    }

    // alternate cards
    int incrementHalf1 = 0;
    int incrementHalf2 = 0;
    for (int j = 0; j < PACK_SIZE; j++)
    {
      if (j % 2 == 0)
      {
        cards[j] = half2[incrementHalf2];
        incrementHalf2++;
      }
      else 
      {
        cards[j] = half1[incrementHalf1];
        incrementHalf1++;
      }
    }
  }
  next = 0;
}

bool Pack::empty() const
{
  return next == 24;
}
