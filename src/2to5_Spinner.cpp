/**
 * @author Todd Across The Mountain [t.acrossthemountain@uleth.ca]
 * @date 2024-10
 */

#include "2to5_Spinner.hpp"
#include "MakeRandomInt.hpp"
#include <iostream>
#include <string>

//Instantiate instance of MakeRandomInt
MakeRandomInt* rng = MakeRandomInt::getInstance();

//overridden Spin function
int FiveSpinner::spin(std::string Stakes) {
  int NumberSpin;
  //get random number from our range 2-5
  NumberSpin = rng->getValue(4) + 2;

  if (Stakes == "Low") {
   NumberSpin = LowStakes(NumberSpin);
  } else if (Stakes == "High") {
   NumberSpin = HighStakes(NumberSpin);
  }

  return NumberSpin;
}

//HighStakes
int FiveSpinner::HighStakes(int NumberGuessed) {
  if (NumberGuessed <= 3) {
    NumberGuessed += rng->getValue(3) + 1; //add random number to low guess from range 1-2
  }

  return NumberGuessed;
}

int FiveSpinner::LowStakes(int NumberGuessed) {
  //if our guess is greater than or = 4
  // generate a random number from 1-2 to minus to make our number lower
  if (NumberGuessed >= 4) {
    NumberGuessed -= rng->getValue(2) + 1;
  }

  return NumberGuessed;
}
