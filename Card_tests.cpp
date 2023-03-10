// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Card.h"
#include "unit_test_framework.h"
#include <iostream>
#include <cassert>
#include <fstream>

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

TEST(card_less_one){

Card a(KING, CLUBS);

Card b(ACE, CLUBS);

bool test = Card_less(b, a, a, HEARTS);

ASSERT_EQUAL(test, 0);

}

TEST(johnny_test){

Card one(JACK, DIAMONDS);

Card two(JACK, HEARTS);

Card led(NINE, DIAMONDS);

bool test = Card_less(one, two, one, HEARTS);

ASSERT_EQUAL(test, 1);

}

TEST(get_rank){

Card test(NINE, SPADES);

ASSERT_EQUAL(test.get_rank(), NINE);

}

TEST(get_suit){

Card test(NINE, SPADES);

ASSERT_EQUAL(test.get_suit(), SPADES);

}

TEST(get_suit_leftBower){

Card test(JACK, SPADES);

ASSERT_EQUAL(test.get_suit(CLUBS), CLUBS);

}

TEST(os_lessThan_op){

Card one(JACK, SPADES);

Card two(TEN, DIAMONDS);

ASSERT_EQUAL((two < one), 1);

}

TEST(less_pr_equal1){

Card one(JACK, SPADES);

Card two(ACE, DIAMONDS);

ASSERT_EQUAL((one <= two), 1);

}

TEST(less_or_equal2){

Card one(JACK, SPADES);

Card two(JACK, DIAMONDS);

ASSERT_EQUAL((one <= two), 1);

}

TEST(suit_next){

Suit suit = SPADES;

ASSERT_EQUAL(Suit_next(suit), CLUBS);

}

TEST(is_equal_to){

Card one(NINE, HEARTS);

Card two(NINE, HEARTS);

Card three(NINE, DIAMONDS);

assert(one == two);

assert((one == three) == 0);

}

TEST(not_equal){

Card one(NINE, DIAMONDS);

Card two(TEN, DIAMONDS);

Card three(NINE, HEARTS);

assert(one != two);

assert(one != three);

}


TEST(greater_equal_1){

Card one(TEN, SPADES);

Card two(JACK, DIAMONDS);

ASSERT_EQUAL((two >= one), 1);

}

TEST(greater_equal_2){

Card one(JACK, SPADES);

Card two(JACK, DIAMONDS);

ASSERT_EQUAL((two >= one), 1);

}

TEST(greater_than){

Card one(TEN, SPADES);

Card two(JACK, DIAMONDS);

ASSERT_EQUAL((two > one), 1);

}

TEST(less_one){

Card one(JACK, HEARTS);

Card two(KING, SPADES);

Card led(TEN, CLUBS);

Suit trump = DIAMONDS;

ASSERT_EQUAL(Card_less(two, one, led, trump), 1);


}

TEST(less_hand){

Card led(JACK, HEARTS);
Card two(JACK, SPADES);
Card three(NINE, DIAMONDS);
Card four(TEN, DIAMONDS);

Suit trump_suit = DIAMONDS;

assert(Card_less(two, led, led, trump_suit));
assert(Card_less(three, led, led, trump_suit));
assert(Card_less(four, led, led, trump_suit));
}

TEST(operator_output){

Card one(NINE, DIAMONDS);
ostringstream os;
operator<<(os, one);

ostringstream os1("Nine of Diamonds");

string test = os.str();
string test1 = os1.str();

ASSERT_EQUAL(test, test1);
}

TEST(test_insert){

string test("Nine of Diamonds");
istringstream test1;
test1 >> test;

Card one;
operator>>(test1, one);

ASSERT_EQUAL(one, Card(NINE, DIAMONDS));
}


TEST_MAIN()
