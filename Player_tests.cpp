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

    ASSERT_EQUAL(real, 1);

    ASSERT_EQUAL(order_up, SPADES);

    delete ali;
}

TEST(test_make_trump_left_bower) {
    Player * ali = Player_factory("Alice", "Simple");

    Card one(TEN, SPADES);
    Card two(QUEEN, CLUBS);
    Card three(NINE, SPADES);
    Card four(ACE, CLUBS);
    Card five(JACK, HEARTS);

    ali->add_card(one);
    ali->add_card(two);
    ali->add_card(three);
    ali->add_card(four);
    ali->add_card(five);


    Card upcard(TEN, DIAMONDS);
    bool is_dealer = 0;
    int round = 2;
    Suit order_up;

    bool real = ali->make_trump(upcard, is_dealer, round, order_up);

    ASSERT_EQUAL(real, 1);

    ASSERT_EQUAL(order_up, HEARTS);

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

TEST(test_play_card_follow_suit) {
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

TEST(test_play_card_no_follow_suit) {
    Player * lice = Player_factory("Alice", "Simple");
    
    
    Card one(NINE, HEARTS);
    Card two(TEN, DIAMONDS);
    Card three(JACK, SPADES);
    Card four(QUEEN, SPADES);
    Card five(ACE, HEARTS);

    lice->add_card(one);
    lice->add_card(two);
    lice->add_card(three);
    lice->add_card(four);
    lice->add_card(five);

    Card led(QUEEN, CLUBS);

    Card test = lice->play_card(led, HEARTS);

    ASSERT_EQUAL(test, two);


    delete lice;
}

TEST(test_play_card_right_bower) {
    Player * lice = Player_factory("Alice", "Simple");
    
    
    Card one(NINE, HEARTS);
    Card two(TEN, DIAMONDS);
    Card three(JACK, SPADES);
    Card four(QUEEN, SPADES);
    Card five(JACK, HEARTS);

    lice->add_card(one);
    lice->add_card(two);
    lice->add_card(three);
    lice->add_card(four);
    lice->add_card(five);

    Card led(QUEEN, HEARTS);

    Card test = lice->play_card(led, HEARTS);

    ASSERT_EQUAL(test, five);


    delete lice;
}

TEST(test_play_card_left_bower) {
    Player * lice = Player_factory("Alice", "Simple");
    
    
    Card one(NINE, HEARTS);
    Card two(JACK, DIAMONDS);
    Card three(JACK, SPADES);
    Card four(QUEEN, SPADES);
    Card five(ACE, HEARTS);

    lice->add_card(one);
    lice->add_card(two);
    lice->add_card(three);
    lice->add_card(four);
    lice->add_card(five);

    Card led(QUEEN, HEARTS);

    Card test = lice->play_card(led, HEARTS);

    ASSERT_EQUAL(test, two);


    delete lice;
}

TEST(test_lead_card_right_bower)
{
    Player* Obama = Player_factory("Obama", "Simple");

    Obama->add_card(Card(NINE, HEARTS));
    Obama->add_card(Card(TEN, HEARTS));
    Obama->add_card(Card(JACK, HEARTS));
    Obama->add_card(Card(QUEEN, HEARTS));
    Obama->add_card(Card(KING, HEARTS));

    ASSERT_EQUAL(Obama->lead_card(HEARTS), Card(JACK, HEARTS));

    delete Obama;
}

TEST(test_lead_card_left_bower)
{
    Player* Obama = Player_factory("Obama", "Simple");

    Obama->add_card(Card(NINE, HEARTS));
    Obama->add_card(Card(TEN, HEARTS));
    Obama->add_card(Card(JACK, DIAMONDS));
    Obama->add_card(Card(QUEEN, HEARTS));
    Obama->add_card(Card(KING, HEARTS));

    ASSERT_EQUAL(Obama->lead_card(HEARTS), Card(JACK, DIAMONDS));

    delete Obama;
}

TEST(test_lead_card_both_bowers)
{
    Player* Obama = Player_factory("Obama", "Simple");

    Obama->add_card(Card(NINE, HEARTS));
    Obama->add_card(Card(TEN, HEARTS));
    Obama->add_card(Card(JACK, DIAMONDS));
    Obama->add_card(Card(JACK, HEARTS));
    Obama->add_card(Card(KING, HEARTS));

    ASSERT_EQUAL(Obama->lead_card(HEARTS), Card(JACK, HEARTS));

    delete Obama;
}

TEST(test_lead_card_only_trump_suit)
{
    Player* Obama = Player_factory("Obama", "Simple");

    Obama->add_card(Card(NINE, HEARTS));
    Obama->add_card(Card(TEN, HEARTS));
    Obama->add_card(Card(ACE, HEARTS));
    Obama->add_card(Card(QUEEN, HEARTS));
    Obama->add_card(Card(KING, HEARTS));

    ASSERT_EQUAL(Obama->lead_card(HEARTS), Card(ACE, HEARTS));

    delete Obama;
}

TEST(test_lead_card_only_off_suit)
{
    Player* Obama = Player_factory("Obama", "Simple");

    Obama->add_card(Card(NINE, CLUBS));
    Obama->add_card(Card(TEN, SPADES));
    Obama->add_card(Card(ACE, CLUBS));
    Obama->add_card(Card(QUEEN, SPADES));
    Obama->add_card(Card(KING, CLUBS));

    ASSERT_EQUAL(Obama->lead_card(HEARTS), Card(ACE, CLUBS));

    delete Obama;
}

TEST(test_add_discard_bower)
{
    Player* Obama = Player_factory("Obama", "Simple");

    Obama->add_card(Card(TEN, CLUBS));
    Obama->add_card(Card(TEN, CLUBS));
    Obama->add_card(Card(TEN, CLUBS));
    Obama->add_card(Card(TEN, CLUBS));
    Obama->add_card(Card(NINE, CLUBS));

    Obama->add_and_discard(Card(JACK, HEARTS));

    ASSERT_EQUAL(Obama->lead_card(SPADES), Card(JACK, HEARTS));

    delete Obama;
}

TEST(test_add_discard_upcard_is_lowest)
{
    Player* Obama = Player_factory("Obama", "Simple");

    Obama->add_card(Card(TEN, CLUBS));
    Obama->add_card(Card(JACK, CLUBS));
    Obama->add_card(Card(QUEEN, CLUBS));
    Obama->add_card(Card(KING, CLUBS));
    Obama->add_card(Card(ACE, CLUBS));

    Obama->add_and_discard(Card(NINE, CLUBS));

    ASSERT_EQUAL(Obama->play_card(Card(KING, HEARTS), CLUBS), Card(TEN, CLUBS));

    delete Obama;
}

TEST(test_more_make_trump)
{
    Player* const a = Player_factory("a", "Simple");

    Suit ou = SPADES;
    a->add_card(Card(KING, SPADES));
    a->add_card(Card(QUEEN, SPADES));
    a->add_card(Card(KING, CLUBS));
    a->add_card(Card(QUEEN, CLUBS));
    a->add_card(Card(KING, HEARTS));

    ASSERT_TRUE(a->make_trump(Card(NINE, SPADES), 1, 1, ou));
    ASSERT_TRUE(a->make_trump(Card(NINE, SPADES), 0, 1, ou));
    ASSERT_TRUE(a->make_trump(Card(NINE, SPADES), 0, 1, ou));

    delete a;
}

TEST(test_make_trump_as_dealer){
    Player* const a = Player_factory("a", "Simple");

    Suit ou = HEARTS;
    a->add_card(Card(KING, SPADES));
    a->add_card(Card(QUEEN, SPADES));
    a->add_card(Card(KING, CLUBS));
    a->add_card(Card(QUEEN, CLUBS));
    a->add_card(Card(KING, HEARTS));

    ASSERT_TRUE(a->make_trump(Card(NINE, DIAMONDS), 1, 2, ou));

    delete a;
}

TEST(test_operator_overload)
{
    Player* const a = Player_factory("a", "Simple");
    stringstream os;
    stringstream correct;
    os << *a;
    correct << "a";
    ASSERT_EQUAL(os.str(), correct.str());

    delete a;
}

TEST(test_player_factory)
{
    Player* const a = Player_factory("a", "Simple");

    ASSERT_EQUAL(typeid(*a), typeid(Player));
    ASSERT_EQUAL(a->get_name(), "a");

    delete a;
}

TEST(test_play_cards_in_correct_order)
{
    Player* const a = Player_factory("a", "Simple");

    a->add_card(Card(KING, SPADES)); 
    a->add_card(Card(QUEEN, SPADES)); 
    a->add_card(Card(KING, CLUBS));
    a->add_card(Card(TEN, HEARTS)); 
    a->add_card(Card(KING, HEARTS)); 

    Card played = a->play_card(Card(NINE, SPADES), DIAMONDS);
    ASSERT_EQUAL(played, Card(KING, SPADES));
    Card played = a->play_card(Card(NINE, DIAMONDS), DIAMONDS);
    ASSERT_EQUAL(played, Card(TEN, HEARTS));
    Card played = a->play_card(Card(NINE, HEARTS), DIAMONDS);
    ASSERT_EQUAL(played, Card(KING, HEARTS));
    Card played = a->play_card(Card(NINE, HEARTS), DIAMONDS);
    ASSERT_EQUAL(played, Card(QUEEN, SPADES));
    Card played = a->play_card(Card(NINE, DIAMONDS), DIAMONDS);
    ASSERT_EQUAL(played, Card(KING, CLUBS));
}

TEST_MAIN()
