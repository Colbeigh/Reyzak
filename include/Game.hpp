/**
 * payout.hpp created by Colby Hanna (Colby.Hanna@uleth.ca) on 2024-09-29
 */

#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Spinner.hpp"
#include "Payout.hpp"

class Game {
 public:
  Game();
  virtual ~Game();
  
  void Start();

  Player player;

  private:
  void Stakes(int bet);
  void SelectSpinner();
  void Hit();
  void Exit();
  void Rules();

  Spinner* current_spinner;

};

#endif
