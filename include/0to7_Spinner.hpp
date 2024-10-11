#ifndef ZEROTOSEVENSPINNER_H
#define ZEROTOSEVENSPINNER_H

#include "Spinner.hpp"
#include <iostream>
#include <string>

/**
 * @class SevenSpinner 0to7_Spinner.hpp "0to7_Spinner.hpp"
 * @brief an inherited class that applies polymorphism on spin and stakes functionality within the range of 0-7
 */
class SevenSpinner : public Spinner {
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
  * @brief Manipulates NumberGuessed by Spinner to bias lower numbers if stakes are low and guess is high
  * @param NumberGuessed int guessed by the Spinner in spin
  * @return NumberGuessed either manipulated or not depending on if NumberGuessed was high
  */
  int LowStakes(int NumberGuessed) override;

 /**
  * @brief Manipulates NumberGuessed by Spinner to bias higher numbers if stakes are high and guess is low
  * @param NumberGuessed int guessed by the Spinner in spin
  * @return NumberGuessed either manipulated or not depending on if NumberGuessed was high
  */
  int HighStakes(int NumberGuessed) override;
};

#endif
