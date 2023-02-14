// Project UID 1d9f47bfc76643019cfbf037641defe1
#include "Pack.h"
#include <cassert>
#include <cmath>
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
  // create arrays to store half of deck each
  Card *h1 = new Card[PACK_SIZE / 2];
  Card *h2 = new Card[PACK_SIZE / 2];
  const int NUM_SHUFFLES = 7;
  const int HALF = PACK_SIZE / 2;

  // shuffle loop
  for (int shuffle = 0; shuffle < NUM_SHUFFLES; shuffle++)
  {
    // split deck in two halves
    for (int i = 0; i < PACK_SIZE; i++)
    {
      if (i < HALF)
      {
        h1[i] = cards[i];
      }
      else 
      {
        h2[i - HALF] = cards[i];
      }
    }

    // combine halves, alternating, starting with h2
    for (int i = 0; i < PACK_SIZE; i += 2)
    {
      cards[i] = h2[i / 2];
    }
    for (int i = 1; i < PACK_SIZE; i += 2)
    {
      cards[i] = h1[i / 2];
    }
  }

  delete[] h1;
  delete[] h2; 
  next = 0;
}

bool Pack::empty() const
{
  return next == 24;
}
