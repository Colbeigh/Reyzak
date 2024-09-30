//Player Class
//Author: Jem

#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

class Player

{
  
 public:
  //Constructors
  Player();

  Player(int pScore, int currentScore);

  //Deconstructors
  ~Player();

  void Placebet(int amount);

  void UpdateScore(int spinResult);

  bool Bust();



  };

#endif //PLAYER_HPP_INCLUDED
