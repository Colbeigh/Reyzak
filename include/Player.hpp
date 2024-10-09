/**
 * @author Jem Pineda <j.pineda@uleth.ca>
 * @date Fall 2024
*/
#include "Payout.hpp"
#include "PWallet.hpp"
#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED
/**
 * @class Player Player.hpp "Player.hpp"
 * @brief Handles scores, placing bets and returns payout.
 */
class Player{
 public:
 /**
  * @brief Default constructor that Initializes bet and scores values.
  */
  Player();
  /**
  * @brief Accepts user input to place a bet and
  * remove currency appropriately.
  */
  void placeBet();
  /**
  * @brief Determines whether the score has hit above 17.
  * @return true if score is greater than 17, false otherwise
  */
  bool Bust();
  /**
  * @brief Access currency
  * @return the currency 
  */
  double getBalance();
  /**
  * @brief Access the payout
  * @return the payout
  */
  void getPayout();
  int currentscore;
  double currentbet;

 private:
Payout Pay;
PWallet Wallet;
};

#endif //PLAYER_HPP_INCLUDED
