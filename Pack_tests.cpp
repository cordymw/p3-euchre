// Project UID 1d9f47bfc76643019cfbf037641defe1

#include "Pack.h"
#include "unit_test_framework.h"

#include <iostream>

using namespace std;

TEST(test_pack_default_ctor) {
    Pack pack;
    Card first = pack.deal_one();
    ASSERT_EQUAL(NINE, first.get_rank());
    ASSERT_EQUAL(SPADES, first.get_suit());
}

TEST(deal_adi_debugging){

Pack pack;

Card q;
Card qw;
Card qwe;
Card qwer;
Card qwert;
Card qwerty;
Card qwertyu;
Card qwertyui;
Card qwertyuio;
Card qwertyuiop;

//first round of dealing (3-2-3-2)
q = pack.deal_one();
qw = pack.deal_one();
qwe = pack.deal_one();


qwer = pack.deal_one();
qwert = pack.deal_one();


qwerty = pack.deal_one();
qwertyu = pack.deal_one();
qwertyui = pack.deal_one();

//adi's cards dealt to her
qwertyuio = pack.deal_one();
qwertyuiop = pack.deal_one();



cout << qwertyuio << endl;
cout << "Jack of Hearts" << endl;

cout << endl;

cout << qwertyuiop << endl;
cout << "Queen of Hearts" << endl;

cout << endl;



//second round of dealing (2-3-2-3)
q = pack.deal_one();
qw = pack.deal_one();


qwe = pack.deal_one();
qwer = pack.deal_one();
qwert = pack.deal_one();


qwerty = pack.deal_one();
qwertyu = pack.deal_one();

//adi's cards dealt to her
qwertyui = pack.deal_one();
qwertyuio = pack.deal_one();
qwertyuiop = pack.deal_one();

cout << qwertyui << endl;
cout << "Ace of Clubs" << endl;

cout << endl;

cout << qwertyuio << endl;
cout << "Nine of Diamonds" << endl;

cout << endl;

cout << qwertyuiop << endl;
cout << "Ten of Diamonds" << endl;

cout << endl;


//upcard would be
cout << pack.deal_one() << endl;

cout << "Jack of Diamonds" << endl;

cout << endl;

}

// Add more tests here

TEST_MAIN()
