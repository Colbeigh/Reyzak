/**
 * @author Todd Across The Mountain [t.acrossthemountain@uleth.ca]
 * @date 2024-10
 */

#include "Spinner_0to7.hpp"

int Spinner_0to7::spin(std::string Stakes) {
  MakeRandomInt* rng = MakeRandomInt::getInstance();
  int guess = rng->getValue(8);

  if (Stakes == "Low") {
    guess = LowStakes(guess);
  } else if (Stakes == "High") {
    guess = HighStakes(guess);
  }

  return guess;
}

int Spinner_0to7::LowStakes(int NumberGuessed) {
  if (NumberGuessed >= 4) {
    MakeRandomInt* rng = MakeRandomInt::getInstance();
    NumberGuessed -= rng->getValue(3) + 1;
  }

  return NumberGuessed;
}

int Spinner_0to7::HighStakes(int NumberGuessed) {
  MakeRandomInt* rng = MakeRandomInt::getInstance();
  if (NumberGuessed <= 4) {
    NumberGuessed += rng->getValue(3) + 1;
  }

  return NumberGuessed;
}
