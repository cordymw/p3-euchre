// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Player.h"
#include "unit_test_framework.h"
#include <cassert>
#include <iostream>

using namespace std;

TEST(test_player_get_name) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());

    delete alice;
}

TEST(test_add_card_and_handsize_and_handat) {
    Player * alice = Player_factory("Alice", "Simple");
    
    Card test(NINE, HEARTS);
    alice->add_card(test);

    ASSERT_EQUAL(alice->hand_size(), 1);


    Card pls = alice->hand_at(0);
    ASSERT_EQUAL(pls, test);

    delete alice;
}



//SIMPLE


TEST(test_make_trump_simple) {
    Player * alice = Player_factory("Alice", "Simple");

    Card one(NINE, HEARTS);
    Card two(TEN, DIAMONDS);
    Card three(JACK, SPADES);
    Card four(QUEEN, CLUBS);
    Card five(ACE, HEARTS);

    alice->add_card(one);
    alice->add_card(two);
    alice->add_card(three);
    alice->add_card(four);
    alice->add_card(five);

    Card upcard(TEN, SPADES);
    bool is_dealer = 0;
    int round = 1;
    Suit order_up;

    bool real = alice->make_trump(upcard, is_dealer, round, order_up);

    assert(real == 1);

    delete alice;
}

TEST(test_add_discard_simple) {
    Player * alice = Player_factory("Alice", "Simple");
    
    Card one(NINE, HEARTS);
    Card two(TEN, DIAMONDS);
    Card three(JACK, SPADES);
    Card four(QUEEN, CLUBS);
    Card five(ACE, HEARTS);

    alice->add_card(one);
    alice->add_card(two);
    alice->add_card(three);
    alice->add_card(four);
    alice->add_card(five);

    Card upcard(TEN, SPADES);

    alice->add_and_discard(upcard);

    for(int i= 0; i<5; ++i){

        Card test = alice->hand_at(i);

        ASSERT_NOT_EQUAL(test, one);

    }

    delete alice;
}

TEST(test_lead_card_simple) {
    Player * alice = Player_factory("Alice", "Simple");
    
    
    Card one(NINE, HEARTS);
    Card two(TEN, DIAMONDS);
    Card three(JACK, SPADES);
    Card four(QUEEN, CLUBS);
    Card five(ACE, HEARTS);

    alice->add_card(one);
    alice->add_card(two);
    alice->add_card(three);
    alice->add_card(four);
    alice->add_card(five);

    Card test= alice->lead_card(HEARTS);

    ASSERT_EQUAL(test, four);


    delete alice;
}

TEST(test_play_card_simple) {
    Player * alice = Player_factory("Alice", "Simple");
    
    
    Card one(NINE, HEARTS);
    Card two(TEN, DIAMONDS);
    Card three(JACK, SPADES);
    Card four(QUEEN, CLUBS);
    Card five(ACE, HEARTS);

    alice->add_card(one);
    alice->add_card(two);
    alice->add_card(three);
    alice->add_card(four);
    alice->add_card(five);

    Card led(QUEEN, SPADES);

    Card test = alice->play_card(led, HEARTS);

    ASSERT_EQUAL(test, three);


    delete alice;
}




//HUMAN

TEST(test_make_trump_human) {
    Player * alice = Player_factory("Alice", "Human");
    
    
    Card one(NINE, HEARTS);
    Card two(TEN, DIAMONDS);
    Card three(JACK, SPADES);
    Card four(QUEEN, CLUBS);
    Card five(ACE, HEARTS);

    alice->add_card(one);
    alice->add_card(two);
    alice->add_card(three);
    alice->add_card(four);
    alice->add_card(five);

    Card upcard(TEN, SPADES);

    //when testing i will enter HEARTS and say yes
    bool is_dealer = 0;
    int round = 1;
    Suit order_up;

    bool real = alice->make_trump(upcard, is_dealer, round, order_up);

    ASSERT_EQUAL(real, 1);


    delete alice;
}

TEST(test_add_discard_human) {
    Player * alice = Player_factory("Alice", "Human");
    
    
    Card one(NINE, HEARTS);
    Card two(TEN, DIAMONDS);
    Card three(JACK, SPADES);
    Card four(QUEEN, CLUBS);
    Card five(ACE, HEARTS);

    alice->add_card(one);
    alice->add_card(two);
    alice->add_card(three);
    alice->add_card(four);
    alice->add_card(five);

    Card upcard(TEN, SPADES);

    //i will choose to get rid of card one, 9 of hearts
    alice->add_and_discard(upcard);

    for(int i= 0; i<5; ++i){

        Card test = alice->hand_at(i);

        ASSERT_NOT_EQUAL(test, one);

    }

    delete alice;
}

TEST(test_lead_card_human) {
    Player * alice = Player_factory("Alice", "Human");
    
    
    Card one(NINE, HEARTS);
    Card two(TEN, DIAMONDS);
    Card three(JACK, SPADES);
    Card four(QUEEN, CLUBS);
    Card five(ACE, HEARTS);

    alice->add_card(one);
    alice->add_card(two);
    alice->add_card(three);
    alice->add_card(four);
    alice->add_card(five);

    Suit trump = SPADES;
    Card test = alice->lead_card(trump);
    //i will choose to play the jack of spades, card three
    ASSERT_EQUAL(test, three);

    delete alice;
}

TEST(test_play_card_human) {
    Player * alice = Player_factory("Alice", "Human");
    
    
    Card one(NINE, HEARTS);
    Card two(TEN, DIAMONDS);
    Card three(JACK, SPADES);
    Card four(QUEEN, CLUBS);
    Card five(ACE, HEARTS);

    alice->add_card(one);
    alice->add_card(two);
    alice->add_card(three);
    alice->add_card(four);
    alice->add_card(five);

    Suit trump = SPADES;
    Card led(ACE, DIAMONDS);

    Card test = alice->play_card(led, trump);
    //i will choose to play the jack of spades, card three
    ASSERT_EQUAL(test, three);

    delete alice;
}



TEST_MAIN()
