//Player Class
//Author: Jem

#include "PWallet.hpp"
#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

class Player

{
  
 public:
  //Constructors
  Player();

  Player(int &pScore, double &pBet, PWallet Wallet);

  //Deconstructors
  ~Player();

  
  void placeBet(double currentBet);

  bool Bust();

  int getScore();

private:

int* currentScore;
int* currentBet;

  };

#endif //PLAYER_HPP_INCLUDED
