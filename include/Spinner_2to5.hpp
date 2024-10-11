#ifndef SPINNER_2TO5_HPP
#define SPINNER_2TO5_HPP

#include "Spinner.hpp"
#include "MakeRandomInt.hpp"
#include <string>

/**
 * @class Spinner_2to5 Spinner_2to5.hpp "Spinner_2to5.hpp"
 * @brief An inherited class that applies polymorphism on spin and Stakes functionality within the range 2-5
 */
class Spinner_2to5 : public Spinner {
 public:
  /**
   * @brief returns a random number from within the range
   * @details depending on stakes given, the function uses MakeRandomInt to generate numbers to apply
   * Bias to the result, it calls the HighStakes and LowStakes functions to do this. If no bias then just returns
   * Random number from within range
   * @param Stakes string parsed from game to determine the stakes given by the player
   * @return Random number from within range and manipulated depending on Stakes Bias
   */
  int spin(std::string Stakes) override;

  /**
   * @brief Manipulates NumberGuessed by Spinner to bias higher numbers if stakes are high and guess is low
   * @param NumberGuessed int guessed by the Spinner in spin
   * @return NumberGuessed either manipulated or not depending on if NumberGuessed was low
   */
  int HighStakes(int NumberGuessed) override;

  /**
   * @brief Manipulates NumberGuessed by Spinner to bias lower numbers if stakes are low and guess is too high
   * @param NumberGuessed int guessed by the Spinner in spin
   * @return NumberGuessed either manipulated or not depending on if NumberGuessed was high
   */
  int LowStakes(int NumberGuessed) override;
};

#endif
