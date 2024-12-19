/**
 * @author Todd Across The Mountain [t.acrossthemountain@uleth.ca]
 * @date 2024-10
 */

#include "Spinner_2to5.hpp"

int Spinner_2to5::Spin(std::string Stakes) {
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

int Spinner_2to5::HighStakes(int NumberGuessed) {
  MakeRandomInt* rng = MakeRandomInt::getInstance();
  if (NumberGuessed <= 3) {
    NumberGuessed += rng->getValue(2) + 1;
  }

  return NumberGuessed;
}

int Spinner_2to5::LowStakes(int NumberGuessed) {
  MakeRandomInt* rng = MakeRandomInt::getInstance();
  if (NumberGuessed >= 4) {
    NumberGuessed -= rng->getValue(2) + 1;
  }

  return NumberGuessed;
}
