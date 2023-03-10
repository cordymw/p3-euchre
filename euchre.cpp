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
        Player * maker;//identified

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

  temp_t1 = 0;
  temp_t2 = 0;

  if(dealer_index == leader_index){
    cout << "smth wrong bruh" << endl;
  }
}

void Game::play_game()
{
  int handNum = 0;

  while (t1_pts < pt_target || t2_pts < pt_target)
  {
    play_hand(handNum);


  if(t1_pts >= pt_target || t2_pts >= pt_target){
    break;
  }


    ++handNum;

    ++dealer_index;

  if(dealer_index == 4){
    dealer_index = 0;
  }
  
  dealer = players[dealer_index];
  }
  

   if (t1_pts >= pt_target){
  //   cout << endl;
    cout << *players[0] << " and " << *players[2] << " win!" << endl;
  }

  if(t2_pts >= pt_target){
  //  cout << endl;
    cout << *players[1] << " and " << *players[3] << " win!" << endl;
  }

  for(int i = 0; i < players.size(); ++i){
    delete players[i];
  }

}

void Game::play_hand(int handNum)
{

  //announce hand, upcard, and dealer
  cout << "Hand " << handNum << endl;
  cout << *dealer << " deals" << endl;


  const int NUM_TRICKS = 5;
  temp_t1 = 0;
  temp_t2 = 0;

  if (shuffle == 1)
  {
    pack.shuffle();
  }

  pack.reset();
  deal();

  set_up_card();
  cout<< upcard << " turned up" << endl;

  trump_suit = play_round_1();

  for (int trick = 0; trick < NUM_TRICKS; trick++)
  {
    play_trick();
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



//march/euchred possibilities

//team 1 made trump

  if((maker == players[0]) || (maker == players[2])){

    if((temp_t1 == 0) || (temp_t1 == 1) || (temp_t1 == 2)){
      cout << "euchred!" << endl;
      ++t2_pts;
    }

    if(temp_t1 == 5){
      cout << "march!" << endl;
      ++t1_pts;
    }

  }

  //team 2 made trump
  else{

    if((temp_t2 == 0) || (temp_t2 == 1) || (temp_t2 == 2)){
      cout << "euchred!" << endl;
      ++t1_pts;
    }

    if(temp_t2 == 5){
      cout << "march!" << endl;
      ++t2_pts;
    }

  }
  


  //points count
   cout << *players[0] << " and " << *players[2] << " have " 
   << t1_pts << " points" << endl;
   cout << *players[1] << " and " << *players[3] << " have " 
   << t2_pts << " points" << endl;
   cout << endl;


  if(leader_index == 4){
    leader_index = 0;
  }



//end of play hand
}

void Game::deal()
{
  int deal_index = dealer_index + 1;


  if(deal_index == 4){
    deal_index = 0;
  }


  //first round of dealing
  for(int i = 0; i < 2; ++i){

    for(int j = 0; j < 3; ++j){

      players[deal_index]->add_card(pack.deal_one());
    }

    ++deal_index;
      if(deal_index == 4){
      deal_index = 0;
      }

    for(int j = 0; j < 2; ++j){

      players[deal_index]->add_card(pack.deal_one());
    }

      ++deal_index;
      if(deal_index == 4){
      deal_index = 0;
      }

  }

deal_index = dealer_index + 1;
if(deal_index == 4){
  deal_index = 0;
}

//second round of dealing
  for(int i = 0; i < 2; ++i){

    for(int j = 0; j < 2; ++j){

      players[deal_index]->add_card(pack.deal_one());
    }

    ++deal_index;
      if(deal_index == 4){
      deal_index = 0;
      }

    for(int j = 0; j < 3; ++j){

      players[deal_index]->add_card(pack.deal_one());
    }

      ++deal_index;
      if(deal_index == 4){
      deal_index = 0;
      }

  }

//end of deal
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

  if(player_index == 4){
    player_index = 0;
  }

  int round = 1;

  for(int i = 0; i < 2; ++i){
    for(int i = 0; i < 4; ++i){

      bool is_dealer = 0;
      if(player_index == dealer_index){
        is_dealer = 1;
      }


      making_trump = //continues below
      players[player_index]->make_trump(upcard, is_dealer, round, order_up);

      if(making_trump == 0){

        cout << players[player_index]->get_name() << " passes" << endl;
        ++player_index;

      }

      if(player_index == 4){
          player_index = 0;
        }

      if(making_trump == 1){

        trump_suit = order_up;
        break;
      }
    }
    if(making_trump == 1){
      break;
    }
    ++round;
  }

  leader_index = dealer_index + 1;
  if(leader_index == 4){
    leader_index = 0;
  }

  cout << players[player_index]->get_name() << " orders up " << trump_suit << endl;
  cout << endl;

  if(round == 1){
  dealer->add_and_discard(upcard);
  }

  maker = players[player_index];

  return trump_suit;


//end of play round
}



void Game::play_trick()
{

  //CARD PLAYING


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

  



  //WHO WON TRICK


  //if leader was player[0]
if(players[leader_index] == players[0]){
  //they are on team one

  if(Card_less(two, led, led, trump_suit) && 
  Card_less(four, led, led, trump_suit) && 
  Card_less(three, led, led, trump_suit)){
    //player 0, leader, takes the trick

    ++temp_t1;
    cout << *players[leader_index] << " takes the trick" << endl;
    cout << endl;
  }
  else if(Card_less(two, three, led, trump_suit) && 
  Card_less(four, three, led, trump_suit) && 
  Card_less(led, three, led, trump_suit)){
    //player 0 teammate player 2 takes the trick

    ++temp_t1;

    cout << *players[2] << " takes the trick" << endl;
    cout << endl;
    leader_index = 2;
  }

  //if winner is on team two
  else if(Card_less(led, two, led, trump_suit) && 
  Card_less(three, two, led, trump_suit) && 
  Card_less(four, two, led, trump_suit)){
  //player 1 wins the trick

    ++temp_t2;

    cout << *players[1] << " takes the trick" << endl;
    cout << endl;
    leader_index = 1;
  }
  //the other 3 cards didnt win, so that means this final card 4 won
  else{
    //player 3 won the trick

    ++temp_t2;

    cout << *players[3] << " takes the trick" << endl;
    cout << endl;
    leader_index = 3;
  }
  }


  //if leader is player[1]
else if(players[leader_index] == players[1]){
//bro is on team 2

  if(Card_less(two, led, led, trump_suit) && 
  Card_less(four, led, led, trump_suit) && 
  Card_less(three, led, led, trump_suit)){

    ++temp_t2;

    cout << *players[leader_index] << " takes the trick" << endl;
    cout << endl;

  }
  else if(Card_less(two, three, led, trump_suit) && 
  Card_less(four, three, led, trump_suit) &&
  Card_less(led, three, led, trump_suit)){

    ++temp_t2;

    cout << *players[3] << " takes the trick" << endl;
    cout << endl;
    leader_index = 3;
  }
  else if(Card_less(led, two, led, trump_suit) && 
  Card_less(three, two, led, trump_suit) && 
  Card_less(four, two, led, trump_suit)){

    ++temp_t1;

    cout << *players[2] << " takes the trick" << endl;
    cout << endl;
    leader_index = 2;
  }
  else{

    ++temp_t1;

    cout << *players[0] << " takes the trick" << endl;
    cout << endl;
    leader_index = 0;
  }
}


else if(players[leader_index] == players[2]){
    //player[2] was leader

    if(Card_less(two, led, led, trump_suit) && 
    Card_less(four, led, led, trump_suit) && 
    Card_less(three, led, led, trump_suit)){

    ++temp_t1;

    cout << *players[leader_index] << " takes the trick" << endl;
    cout << endl;

//Ivan Human Judea Human Kunle Human Liskov Human

  }
  else if(Card_less(two, three, led, trump_suit) && 
  Card_less(four, three, led, trump_suit) && 
  Card_less(led, three, led, trump_suit)){

    ++temp_t1;

    cout << *players[0] << " takes the trick" << endl;
    cout << endl;
    leader_index = 0;
  }
  else if(Card_less(led, two, led, trump_suit) && 
  Card_less(three, two, led, trump_suit) && 
  Card_less(four, two, led, trump_suit)){

    ++temp_t2;

    cout << *players[3] << " takes the trick" << endl;
    cout << endl;
    leader_index = 3;
  }
  else{

    ++temp_t2;

    cout << *players[1] << " takes the trick" << endl;
    cout << endl;
    leader_index = 1;
  }
  }


  //if leader = player[3]
//if(players[leader_index] == players[3])
else{

    if(Card_less(two, led, led, trump_suit) && 
    Card_less(four, led, led, trump_suit) && 
    Card_less(three, led, led, trump_suit)){

    ++temp_t2;

    cout << *players[leader_index] << " takes the trick" << endl;
    cout << endl;

  }
  else if(Card_less(two, three, led, trump_suit) && 
  Card_less(four, three, led, trump_suit) && 
  Card_less(led, three, led, trump_suit)){

    ++temp_t2;

    cout << *players[1] << " takes the trick" << endl;
    cout << endl;
    leader_index = 1;
  }
  else if(Card_less(led, two, led, trump_suit) && 
  Card_less(three, two, led, trump_suit) && 
  Card_less(four, two, led, trump_suit)){

    ++temp_t1;

    cout << *players[0] << " takes the trick" << endl;
    cout << endl;
    leader_index = 0;
  }
  else{

    ++temp_t1;

    cout << *players[2] << " takes the trick" << endl;
    cout << endl;
    leader_index = 2;
  }
  }




//end of play trick
}



//end of game adt
//start of driver


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

  int pts = atoi(argv[3]);

  Game game(game_pack, shuffled, pts, players);

  for(int i = 0; i < argc; ++i){

    cout << string(argv[i]) << " ";
  }
  cout << endl;

  game.play_game();

  

  return 0;
}


//3456789022345678903234567890423456789052345678906234567890723456789082345678909234567890
