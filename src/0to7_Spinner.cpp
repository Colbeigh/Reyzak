/**
 * @author Todd Across The Mountain [t.acrossthemountain@uleth.ca]
 * @date 2024-10
 */

#include "0to7_Spinner.hpp"
#include "MakeRandomInt.hpp"
#include <string>

//instantiate MakeRandomInt
MakeRandomInt* rng = MakeRandomInt::getInstance();

int SevenSpinner::spin(std::string Stakes) {
  //Get random value from 0-7 range
  int guess = rng->getValue(8);

  if (Stakes == "Low") {
    guess = LowStakes(guess);
  } else if (Stakes == "High") {
    guess = HighStakes(guess);
  }

  return guess;
}

int SevenSpinner::LowStakes(int NumberGuessed) {
  if (NumberGuessed >= 4) {
    NumberGuessed -= rng->getValue(3) + 1; //minuses random number from Range 1-3
  }

  return NumberGuessed;
}

int SevenSpinner::HighStakes(int NumberGuessed) {
  if (NumberGuessed <= 4) {
    NumberGuessed += rng->getValue(3) + 1; // adds random number from range 1-3
  }

  return NumberGuessed;
}
