// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <iostream>
#include "Card.h"
#include "Pack.h"
#include "Player.h"

using namespace std;

class Game 
{
    public:
        Game();
        Game(Pack c, bool s, int pts, vector<Player*> p);

        void play_game();
        void play_hand();
        void play_round_1();
        void play_round_2();
        void play_trick();
        void set_point_target();
        void set_trump_suit();
        void set_up_card();
        void set_led_suit();
        void determine_winning_team(int team);
        void deal(Player* person, int count);
        void add_points(int team);
        void move_leader();

    private:
        Pack pack;
        int pt_target;
        bool shuffle;
        vector<Player*> players;
        Player *dealer;
        Player *leader;
        Card upcard;
        Suit trump_suit;
        Suit led_suit;
        const int t1 = 1;
        const int t2 = 2;
        int t1_pts;
        int t2_pts;
};
