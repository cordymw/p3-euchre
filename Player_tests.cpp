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

TEST(test_player_get_name_human) {
    Player * alice = Player_factory("Alice", "Human");
    ASSERT_EQUAL("Alice", alice->get_name());

    delete alice;
}

TEST(test_add_card) {
    Player * alic = Player_factory("Alice", "Simple");
    
    Card test(NINE, HEARTS);
    alic->add_card(test);

    Card pretend_upcard(TEN,HEARTS);

    ASSERT_EQUAL(alic->play_card(pretend_upcard, HEARTS), test);

    delete alic;
}



//SIMPLE


TEST(test_make_trump_simple) {
    Player * ali = Player_factory("Alice", "Simple");

    Card one(NINE, HEARTS);
    Card two(TEN, DIAMONDS);
    Card three(JACK, SPADES);
    Card four(QUEEN, SPADES);
    Card five(ACE, HEARTS);

    ali->add_card(one);
    ali->add_card(two);
    ali->add_card(three);
    ali->add_card(four);
    ali->add_card(five);

    Card upcard(TEN, SPADES);
    bool is_dealer = 0;
    int round = 1;
    Suit order_up;

    bool real = ali->make_trump(upcard, is_dealer, round, order_up);

    assert(real == 1);

    delete ali;
}

TEST(test_add_discard_simple) {
    Player * al = Player_factory("Alice", "Simple");
    
    Card one(NINE, HEARTS);
    Card two(TEN, DIAMONDS);
    Card three(JACK, DIAMONDS);
    Card four(QUEEN, CLUBS);
    Card five(ACE, HEARTS);

    al->add_card(one);
    al->add_card(two);
    al->add_card(three);
    al->add_card(four);
    al->add_card(five);

    Card upcard(TEN, SPADES);

    al->add_and_discard(upcard);

    Card weed(ACE, SPADES);
    Card pls = al->play_card(weed, SPADES);//al would play nine of hearts if its in their hand
    //since they cant follow suit and its the lowest rank card in their hand

    ASSERT_NOT_EQUAL(pls, one);

    

    delete al;
}

TEST(test_lead_card_simple) {
    Player * a = Player_factory("Alice", "Simple");
    
    
    Card one(NINE, HEARTS);
    Card two(TEN, DIAMONDS);
    Card three(JACK, SPADES);
    Card four(QUEEN, CLUBS);
    Card five(ACE, HEARTS);

    a->add_card(one);
    a->add_card(two);
    a->add_card(three);
    a->add_card(four);
    a->add_card(five);

    Card test= a->lead_card(HEARTS);

    ASSERT_EQUAL(test, four);


    delete a;
}

TEST(test_play_card_simple) {
    Player * lice = Player_factory("Alice", "Simple");
    
    
    Card one(NINE, HEARTS);
    Card two(TEN, DIAMONDS);
    Card three(JACK, SPADES);
    Card four(QUEEN, CLUBS);
    Card five(ACE, HEARTS);

    lice->add_card(one);
    lice->add_card(two);
    lice->add_card(three);
    lice->add_card(four);
    lice->add_card(five);

    Card led(QUEEN, SPADES);

    Card test = lice->play_card(led, HEARTS);

    ASSERT_EQUAL(test, three);


    delete lice;
}




//HUMAN

TEST(test_make_trump_human) {
    Player * ice = Player_factory("Alice", "Human");
    
    
    Card one(NINE, HEARTS);
    Card two(TEN, DIAMONDS);
    Card three(JACK, SPADES);
    Card four(QUEEN, CLUBS);
    Card five(ACE, HEARTS);

    ice->add_card(one);
    ice->add_card(two);
    ice->add_card(three);
    ice->add_card(four);
    ice->add_card(five);

    Card upcard(TEN, SPADES);

    //when testing i will enter HEARTS and say yes
    bool is_dealer = 0;
    int round = 1;
    Suit order_up;

    bool real = ice->make_trump(upcard, is_dealer, round, order_up);

    ASSERT_EQUAL(real, 1);


    delete ice;
}

TEST(test_add_discard_human) {
    Player * ce = Player_factory("Alice", "Human");
    
    
    Card one(NINE, HEARTS);
    Card two(TEN, DIAMONDS);
    Card three(JACK, SPADES);
    Card four(QUEEN, CLUBS);
    Card five(ACE, HEARTS);

    ce->add_card(one);
    ce->add_card(two);
    ce->add_card(three);
    ce->add_card(four);
    ce->add_card(five);

    Card upcard(TEN, SPADES);

    //i will choose to get rid of index 0, 9 of hearts
    ce->add_and_discard(upcard);

    Card weed(ACE, SPADES);
    Card pls = ce->play_card(weed, SPADES);//al would play nine of hearts if its in their hand
    //since they cant follow suit and its the lowest rank card in their hand

    ASSERT_NOT_EQUAL(pls, one);
    delete ce;
}

TEST(test_lead_card_human) {
    Player * e = Player_factory("Alice", "Human");
    
    
    Card one(NINE, HEARTS);
    Card two(TEN, DIAMONDS);
    Card three(JACK, SPADES);
    Card four(QUEEN, CLUBS);
    Card five(ACE, HEARTS);

    e->add_card(one);
    e->add_card(two);
    e->add_card(three);
    e->add_card(four);
    e->add_card(five);

    Suit trump = SPADES;
    Card test = e->lead_card(trump);
    //i will choose to play the jack of spades, index two
    ASSERT_EQUAL(test, three);

    delete e;
}

TEST(test_play_card_human) {
    Player * aalice = Player_factory("Alice", "Human");
    
    
    Card one(NINE, HEARTS);
    Card two(TEN, DIAMONDS);
    Card three(JACK, SPADES);
    Card four(QUEEN, CLUBS);
    Card five(ACE, HEARTS);

    aalice->add_card(one);
    aalice->add_card(two);
    aalice->add_card(three);
    aalice->add_card(four);
    aalice->add_card(five);

    Suit trump = SPADES;
    Card led(ACE, DIAMONDS);

    Card test = aalice->play_card(led, trump);
    //i will choose to play the jack of spades, index two
    ASSERT_EQUAL(test, three);

    delete aalice;
}



TEST_MAIN()
