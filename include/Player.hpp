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

  //Deconstructors
  ~Player();

  
  void placeBet();

  bool Bust();

  double getBalance();

  int currentscore = 0;
  double currentbet = 0.0;

private:

PWallet Wallet;

  };

#endif //PLAYER_HPP_INCLUDED
