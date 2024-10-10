#ifndef TWOTOFIVESPINNER_HPP
#define TWOTOFIVESPINNER_HPP

#include "Spinner.hpp"
#include "MakeRandomInt.hpp"
#include <string>

/**
 * @brief An inherited class that applies polymorphism on spin functionality depending on players stakes within the range 2-5
 */
class FiveSpinner : public Spinner {
  public:
    //override function for spin
    int spin(std::string Stakes) override;

    //High Stakes function, has bias for higher numbers
    int HighStakes(int NumberGuessed) override;

    //Low Stakes function, has bias for lower numbers
    int LowStakes(int NumberGuessed) override;
};

#endif
