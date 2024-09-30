/**
 * payout.hpp created by Colby Hanna (Colby.Hanna@uleth.ca) on 2024-09-29
 */

#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Spinner.hpp"
#include "Player.hpp"
#include "Payout.hpp"

class Game {
 public:
  Game();

  virtual ~Game();

  void Start();
  void Stakes();
  void SelectSpinner();
  void hit();
  void Exit();
  void Payout();

  Player player;
  Spinner* current_spinner;
};

#endif 