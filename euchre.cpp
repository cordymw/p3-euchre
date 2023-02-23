// Project UID 1d9f47bfc76643019cfbf037641defe1

#include <iostream>
#include <fstream>
#include "Card.h"
#include "Pack.h"
#include "Player.h"
//#include "euchre.h"


using namespace std;


//ehcure.h
class Game 
{
    public:
        Game();//identified
        Game(Pack c, bool s, int pts, const vector<Player*> p);//identified

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



//game implementation
Game::Game(){} 

Game::Game(Pack c, bool s, int pts, const vector<Player*> p) 
{
  pack = c;
  shuffle = s;
  pt_target = pts;
  players = p;

  dealer_index = 0;
  dealer = players[dealer_index];

  int leader_index = dealer_index + 1;
  leader = players[leader_index];
  
  t1_pts = 0;
  t2_pts = 0;

  if(dealer_index == leader_index){
    cout << "smth wrong bruh" << endl;
  }

  
}

void Game::play_game()
{
  int handNum = 0;

  while (t1_pts < pt_target && t2_pts < pt_target)
  {
    play_hand(handNum);
    ++handNum;

    ++dealer_index;

  if(dealer_index == 4){
    dealer_index = 0;
  }
  
  dealer = players[dealer_index];
  }
  

  if (t1_pts == pt_target){
    cout << *players[0] << " and " << *players[2] << " win!" << endl;
  }
  else{
    cout << *players[1] << " and " << *players[3] << " win!" << endl;
  }
}

void Game::play_hand(int handNum)
{

  //announce hand, upcard, and dealer
  cout << "Hand " << handNum << endl;
  cout << *dealer << " deals" << endl;


  const int NUM_TRICKS = 5;
  int temp_t1 = 0;
  int temp_t2 = 0;

  if (shuffle == 1)
  {
    pack.shuffle();
  }

  deal();

  set_up_card();
  cout<< upcard << " turned up" << endl;

  trump_suit = play_round_1();

  for (int trick = 0; trick < NUM_TRICKS; trick++)
  {
    play_trick();
  }


  //march/euchred possibilities
  if(maker == players[0] || players[2]){

    if(temp_t1 == 0){
      cout << "euchred!" << endl;
      ++t2_pts;
    }

    if(temp_t1 == 5){
      cout << "march!" << endl;
      ++t1_pts;
    }

  }
  else{

    if(temp_t2 == 0){
      cout << "euchred!" << endl;
      ++t1_pts;
    }

    if(temp_t2 == 5){
      cout << "march!" << endl;
      ++t2_pts;
    }

  }


  //who won hand/ assigning points
  if(temp_t1 > temp_t2){
    cout << *players[0] << " and " << *players[2] << " win the hand" << endl;
    ++t1_pts;
  }
  else{
    cout << *players[1] << " and " << *players[3] << " win the hand" << endl;
    ++t2_pts;
  }

  //points count
   cout << *players[0] << " and " << *players[2] << " have " << t1_pts << " points" << endl;
   cout << *players[1] << " and " << *players[3] << " have " << t2_pts << " points" << endl;



  if(leader_index == 4){
    leader_index = 0;
  }
}

void Game::deal()
{
//
  int deal_index = dealer_index + 1;
  if(deal_index == 4){
    deal_index = 0;
  }

  players[deal_index]->add_card(pack.deal_one());
  players[deal_index]->add_card(pack.deal_one());
  players[deal_index]->add_card(pack.deal_one());

  ++deal_index;
  if(deal_index == 4){
    deal_index = 0;
  }

  players[deal_index]->add_card(pack.deal_one());
  players[deal_index]->add_card(pack.deal_one());

  ++deal_index;
  if(deal_index == 4){
    deal_index = 0;
  }

  players[deal_index]->add_card(pack.deal_one());
  players[deal_index]->add_card(pack.deal_one());
  players[deal_index]->add_card(pack.deal_one());

  ++deal_index;
  if(deal_index == 4){
    deal_index = 0;
  }

  players[deal_index]->add_card(pack.deal_one());
  players[deal_index]->add_card(pack.deal_one());

  ++deal_index;
  if(deal_index == 4){
    deal_index = 0;
  }
  
  players[deal_index]->add_card(pack.deal_one());
  players[deal_index]->add_card(pack.deal_one());

  ++deal_index;
  if(deal_index == 4){
    deal_index = 0;
  }

  players[deal_index]->add_card(pack.deal_one());
  players[deal_index]->add_card(pack.deal_one());
  players[deal_index]->add_card(pack.deal_one());

  ++deal_index;
  if(deal_index == 4){
    deal_index = 0;
  }

  players[deal_index]->add_card(pack.deal_one());
  players[deal_index]->add_card(pack.deal_one());

  ++deal_index;
  if(deal_index == 4){
    deal_index = 0;
  }

  players[deal_index]->add_card(pack.deal_one());
  players[deal_index]->add_card(pack.deal_one());
  players[deal_index]->add_card(pack.deal_one());

}

void Game::set_up_card()
{
  upcard = pack.deal_one();
}



Suit Game::play_round_1()
{
  bool making_trump = 0;

  Suit order_up = upcard.get_suit();

  int player_index = dealer_index + 1;

  int round = 1;

  for(int i = 0; i < 2; ++i){
    for(int i = 0; i < 4; ++i){

      making_trump = players[player_index]->make_trump(upcard, dealer, round, order_up);

      if(making_trump == 0){

        cout << players[player_index]->get_name() << " passes" << endl;
        ++player_index;

        if(player_index == 4){
          player_index = 0;
        }

      }

      if(making_trump == 1){

        trump_suit = order_up;
        break;

      }
    }
    ++round;
    if(making_trump == 1){
      break;
    }
  }

  leader_index = player_index;

  cout << players[player_index]->get_name() << " orders up " << trump_suit << endl;
  cout << endl;

  dealer->add_and_discard(upcard);

  return trump_suit;

}



void Game::play_trick()
{
  leader = players[leader_index];

  Card led = leader->lead_card(trump_suit);
  cout << led << " led by " << *leader << endl;

  int index = leader_index + 1;
  if(index == 4){
    index = 0;
  }

  Card two = players[index]->play_card(led, trump_suit);
  cout << two << " played by " << *players[index] << endl;

  ++index;
  if(index == 4){
    index = 0;
  }

  Card three = players[index]->play_card(led, trump_suit);
  cout << three << " played by " << *players[index] << endl;

  ++index;
  if(index == 4){
    index = 0;
  }

  Card four = players[index]->play_card(led, trump_suit);
  cout << four << " played by " << *players[index] << endl;

  
  //if leader was player[0]
  if(players[leader_index] == players[0]){
  //they are on team one

  if((Card_less(two, led, led, trump_suit) == 1) && (Card_less(four, led, led, trump_suit) == 1)){
    //player 0, leader, takes the trick

    ++temp_t1;
    cout << *players[leader_index] << " takes the trick (1)" << endl;
    cout << endl;
  }
  else if((Card_less(two, three, led, trump_suit) == 1) && (Card_less(four, three, led, trump_suit) == 1)){
    //player 0 teammate player 2 takes the trick

    ++temp_t1;

    cout << *players[2] << " takes the trick (2)" << endl;
    cout << endl;
    leader_index = 2;
  }
  //if winner is on team two
  else if((Card_less(led, two, led, trump_suit) == 1) && (Card_less(three, two, led, trump_suit) == 1)){
  //player 1 wins the trick

    ++temp_t2;

    cout << *players[1] << " takes the trick (3)" << endl;
    cout << endl;
    leader_index = 1;
  }
  //the other 3 cards didnt win, so that means this final card 4 won
  else{
    //player 3 won the trick

    ++temp_t2;

    cout << *players[3] << " takes the trick (4)" << endl;
    cout << endl;
    leader_index = 3;
  }
  }



  //if leader is player[1]
if(players[leader_index] == players[1]){
//bro is on team 2

  if((Card_less(two, led, led, trump_suit) == 1) && (Card_less(four, led, led, trump_suit) == 1)){

    ++temp_t2;

    cout << *players[leader_index] << " takes the trick (5)" << endl;
    cout << endl;

  }
  else if((Card_less(two, three, led, trump_suit) == 1) && (Card_less(four, three, led, trump_suit) == 1)){

    ++temp_t2;

    cout << *players[3] << " takes the trick (6)" << endl;
    cout << endl;
    leader_index = 3;
  }
  else if((Card_less(led, two, led, trump_suit) == 1) && (Card_less(three, two, led, trump_suit) == 1)){

    ++temp_t1;

    cout << *players[2] << " takes the trick (7)" << endl;
    cout << endl;
  }
  else{

    ++temp_t1;

    cout << *players[0] << " takes the trick (8)" << endl;
    cout << endl;
  }


  //if leader is player[2]
  if(players[leader_index] == players[2]){

    if((Card_less(two, led, led, trump_suit) == 1) && (Card_less(four, led, led, trump_suit) == 1)){

    ++temp_t1;

    cout << *players[leader_index] << " takes the trick (9)" << endl;
    cout << endl;

  }
  else if((Card_less(two, three, led, trump_suit) == 1) && (Card_less(four, three, led, trump_suit) == 1)){

    ++temp_t1;

    cout << *players[0] << " takes the trick (10)" << endl;
    cout << endl;
    leader_index = 3;
  }
  else if((Card_less(led, two, led, trump_suit) == 1) && (Card_less(three, two, led, trump_suit) == 1)){

    ++temp_t2;

    cout << *players[3] << " takes the trick (11)" << endl;
    cout << endl;
  }
  else{

    ++temp_t2;

    cout << *players[1] << " takes the trick (12)" << endl;
    cout << endl;
  }
  }


  //if leader = player[3]
  if(players[leader_index] == players[3]){

    if((Card_less(two, led, led, trump_suit) == 1) && (Card_less(four, led, led, trump_suit) == 1)){

    ++temp_t2;

    cout << *players[leader_index] << " takes the trick (13)" << endl;
    cout << endl;

  }
  else if((Card_less(two, three, led, trump_suit) == 1) && (Card_less(four, three, led, trump_suit) == 1)){

    ++temp_t2;

    cout << *players[1] << " takes the trick (14)" << endl;
    cout << endl;
    leader_index = 3;
  }
  else if((Card_less(led, two, led, trump_suit) == 1) && (Card_less(three, two, led, trump_suit) == 1)){

    ++temp_t1;

    cout << *players[0] << " takes the trick (15)" << endl;
    cout << endl;
  }
  else{

    ++temp_t1;

    cout << *players[2] << " takes the trick (16)" << endl;
    cout << endl;
  }
  }


}


//end of play trick
}






//driver
int main(int argc, char **argv) 
{
  // perform initial checks
string shuffle = argv[2];

string type1 = argv[5];
string type2 = argv[7];
string type3 = argv[9];
string type4 = argv[11];

  if (
      // check 12 args
      argc != 12 || 

      // check points to win is between 1-100
      (atoi(argv[3]) < 0 || atoi(argv[3]) > 100) ||

      // check shuffle arg is "shuffle" or "noshuffle"
      !(shuffle == "shuffle" || shuffle == "noshuffle") ||

      // check each player type is either "Simple" or "Human"
      (
        !(type1 == "Simple" || type1 == "Human") ||
        !(type2 == "Simple" || type2 == "Human") ||
        !(type3 == "Simple" || type3 == "Human") ||
        !(type4 == "Simple" || type4 == "Human")
      )
    )
  {
    cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
     << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
     << "NAME4 TYPE4" << endl;
    
    return 1;
  }

  ifstream inFile;
  inFile.open(argv[1]);

  if (!inFile.is_open()) 
  {
    cout << "Error opening " << argv[1] << endl;
    return 1;
  }

  // set up game pack
  Pack game_pack(inFile);
  inFile.close();

  // set up players
  vector<Player*> players;
  for (int i = 4; i < 12; i += 2)
  {
    int j = i + 1;
    players.push_back(Player_factory(argv[i], argv[j]));
  }

  // set up shuffle
  bool shuffled = 0;
  if (shuffle == "shuffle") 
  {
    shuffled = 1;
  }

  Game game(game_pack, shuffled, atoi(argv[3]), players);
  game.play_game();

  return 0;
}

