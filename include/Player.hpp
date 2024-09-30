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

  Player(int Pscore, int currentBet, PWallet Wallet);

  //Deconstructors
  ~Player();

  
  void Placebet(double currentBet);

  bool Bust();

private:

const static_cast <double>(currentBet);
const targetScore = 17;

  };

#endif //PLAYER_HPP_INCLUDED
