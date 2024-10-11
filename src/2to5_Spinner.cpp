/**
 * @author Todd Across The Mountain [t.acrossthemountain@uleth.ca]
 * @date 2024-10
 */

#include "2to5_Spinner.hpp"
#include "MakeRandomInt.hpp"
#include <iostream>
#include <string>


int FiveSpinner::spin(std::string Stakes) {
  MakeRandomInt* rng = MakeRandomInt::getInstance();
  int NumberSpin;
  NumberSpin = rng->getValue(4) + 2;

  if (Stakes == "Low") {
    NumberSpin = LowStakes(NumberSpin);
  } else if (Stakes == "High") {
    NumberSpin = HighStakes(NumberSpin);
  }

  return NumberSpin;
}

int FiveSpinner::HighStakes(int NumberGuessed) {
  MakeRandomInt* rng = MakeRandomInt::getInstance();
  if (NumberGuessed <= 3) {
    NumberGuessed += rng->getValue(2) + 1;
  }

  return NumberGuessed;
}

int FiveSpinner::LowStakes(int NumberGuessed) {
  MakeRandomInt* rng = MakeRandomInt::getInstance();
  if (NumberGuessed >= 4) {
    NumberGuessed -= rng->getValue(2) + 1;
  }

  return NumberGuessed;
}
