//Player Class
//Author: Jem

#include "Payout.hpp"
#include "PWallet.hpp"
#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

class Player

{
  
 public:
  //Constructors
  Player();
  void placeBet();
  bool Bust();
  double getBalance();
  double Payout();
  int currentscore;
  double currentbet;

private:
Payout Pay;
PWallet Wallet;

  };

#endif //PLAYER_HPP_INCLUDED
