// Minimal source file for a placebo class that does nothing but allows the
// pipeline to pass.

#ifndef GAME_HPP
#define GAME_HPP

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

  //Player player;
  //Spinner* current_spinner;
};

#endif 
