/**
 * Game.hpp created by Colby Hanna (Colby.Hanna@uleth.ca) on 2024-09-29
 */

#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Spinner.hpp"
#include "2to5_Spinner.hpp"
#include "0to7_Spinner.hpp"

#include <iostream>
#include <cctype>
#include <string>
#include <fstream>

/**
 * @class Game Game.hpp "Game.hpp"
 * @brief Manages function for the game and its logic
 */
class Game {
 public:
  Game();
  /**
   * @brief Default constructor for Game. Initializes game components.
   */

  /**
   * @brief Destructor for Game.
   */
  virtual ~Game();

  /**
   * @brief Starts main loop for Reyzak calls all functions.
   */
  void Start();

  /**
   * @brief Stores player information such as bets and scores.
   */
  Player player;

 private:
  /**
   * @brief Handles placing stakes for a bet.
   * @param bet The amount of money the player is betting.
   */
  void Stakes(int bet);

  /**
   * @brief Selects a spinner for the game.
   */
  void SelectSpinner();

  /**
   * @brief Processes the "hit" action during the game.
   */
  void Hit();

  /**
   * @brief Exits the game.
   */
  void Exit();

  /**
   * @brief Displays the rules of the game.
   */
  void Rules();

  /**
   * @brief Pointer to the current spinner being used in the game.
   */
  Spinner* current_spinner;
};

#endif
