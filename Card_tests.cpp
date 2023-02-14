// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Card.h"
#include "unit_test_framework.h"
#include <iostream>
#include <cassert>

using namespace std;


TEST(test_card_ctor) {
    Card c(ACE, HEARTS);
    ASSERT_EQUAL(ACE, c.get_rank());
    ASSERT_EQUAL(HEARTS, c.get_suit());
}

TEST(faceAce){
Card c(ACE, HEARTS);

ASSERT_EQUAL(c.is_face_or_ace(), 1);

Card d(EIGHT, SPADES);
ASSERT_EQUAL(d.is_face_or_ace(), 0);
}

TEST(right_bower){
Card c(JACK, HEARTS);

ASSERT_EQUAL(c.is_right_bower(HEARTS), 1);

ASSERT_EQUAL(c.is_right_bower(SPADES), 0);
}

TEST(left_bower){
Card c(JACK, HEARTS);

ASSERT_EQUAL(c.is_left_bower(DIAMONDS), 1);

ASSERT_EQUAL(c.is_left_bower(SPADES), 0);
}

TEST(is_trump){
Card c(ACE, HEARTS);

ASSERT_EQUAL(c.is_trump(HEARTS), 1);
}

TEST_MAIN()
