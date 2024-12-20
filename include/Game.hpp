/**
 * Game.hpp created by Colby Hanna (Colby.Hanna@uleth.ca) on 2024-09-29
 */

#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Spinner.hpp"
#include "Spinner_2to5.hpp"
#include "Spinner_0to7.hpp"

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
  /**
   * @brief Default constructor for Game. Initializes game components.
   */
  Game();

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

  /**
   * @brief Handles placing stakes for a bet.
   * @param bet The amount of money the player is betting.
   */
  void Stakes(int bet);

    std::string stakes;

  /**
   * @brief Exits the game.
   */
  void Exit();

 private:
  /**
   * @brief Selects a spinner for the game.
   */
  void selectSpinner();

  /**
   * @brief Processes the "hit" action during the game.
   */
  void Hit();

  /**
   * @brief Displays the rules of the game.
   */
  void Rules();

  /**
   * @brief Asks if player would like to play again
   */
  void Playing();

  /**
   * @brief Pointer to the current spinner being used in the game.
   */
  Spinner* current_spinner;

  /**
   * @brief Bool to see if player is still playing the game
   */
    bool isplaying;

    /**
   * @brief Bool to see if player is still wanting to spin
   */
    bool isgambling;
};

#endif
