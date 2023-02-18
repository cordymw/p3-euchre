// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Player.h"
#include "unit_test_framework.h"

#include <iostream>

using namespace std;// Project UID 1d9f47bfc76643019cfbf037641defe1

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

TEST(test_add_card) {
    Player * alice = Player_factory("Alice", "Simple");
    
    Card test(NINE, HEARTS);
    Simple alice.add_card(test);//why do you not work


    delete alice;
}





//SIMPLE


TEST(test_make_trump) {
    Player * alice = Player_factory("Alice", "Simple");

    Card one(NINE, HEARTS);
    Card two(TEN, DIAMONDS);
    Card three(JACK, SPADES);
    Card four(QUEEN, CLUBS);
    Card five(ACE, HEARTS);

    alice.add_card(one);
    alice.add_card(two);
    alice.add_card(three);
    alice.add_card(four);
    alice.add_card(five);

    Card upcard(TEN, SPADES);
    bool is_dealer = 0;
    int round = 1;
    Suit order_up;

    bool real = alice.make_trump(upcard, is_dealer, round, order_up);

    assert(real == 1);

    delete alice;
}

TEST(test_player_get_name) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());

    delete alice;
}

TEST(test_player_get_name) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());

    delete alice;
}

TEST(test_player_get_name) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());

    delete alice;
}




//HUMAN

TEST(test_player_get_name) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());

    delete alice;
}

TEST(test_player_get_name) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());

    delete alice;
}

TEST(test_player_get_name) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());

    delete alice;
}

TEST(test_player_get_name) {// Project UID 1d9f47bfc76643019cfbf037641defe1

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

TEST(test_add_card) {
    Player * alice = Player_factory("Alice", "Simple");
    
    Card test(NINE, HEARTS);
    Simple alice.add_card(test);//why do you not work


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

    alice.add_card(one);
    alice.add_card(two);
    alice.add_card(three);
    alice.add_card(four);
    alice.add_card(five);

    Card upcard(TEN, SPADES);
    bool is_dealer = 0;
    int round = 1;
    Suit order_up;

    bool real = alice.make_trump(upcard, is_dealer, round, order_up);

    assert(real == 1);

    delete alice;
}

TEST(test_add_discard_simple) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());

    delete alice;
}

TEST(test_lead_card_simple) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());

    delete alice;
}

TEST(test_play_card_simple) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());

    delete alice;
}




//HUMAN

TEST(test_make_trump_human) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());

    delete alice;
}

TEST(test_add_discard_human) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());

    delete alice;
}

TEST(test_lead_card_human) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());

    delete alice;
}

TEST(test_play_card_human) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());

    delete alice;
}



TEST_MAIN()

    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());

    delete alice;
}



TEST_MAIN()


TEST(test_player_get_name) {
    Player * alice = Player_factory("Alice", "Simple");
    ASSERT_EQUAL("Alice", alice->get_name());

    delete alice;
}

// Add more tests here

TEST_MAIN()
