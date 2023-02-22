// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <iostream>
#include "Card.h"
#include "Pack.h"
#include "Player.h"

using namespace std;

class Game 
{
    public:
        Game();//identified
        Game(Pack c, bool s, int pts, vector<Player*> p);//identified

        void play_game();//identified
        void play_hand(int handNum);//identified
        Suit play_round_1();//identified
        void play_trick();//identified
        void set_up_card();//identified
        void deal();//identified
        Player * maker;

    private:
        Pack pack;
        int pt_target;
        bool shuffle;
        vector<Player*> players;
        Player *dealer;
        int dealer_index;
        Player *leader;
        int leader_index = 0;
        Card upcard;
        Suit trump_suit;
        Suit led_suit;
        const int t1 = 1;
        const int t2 = 2;
        int t1_pts;
        int t2_pts;
        int temp_t1;
        int temp_t2;
};
