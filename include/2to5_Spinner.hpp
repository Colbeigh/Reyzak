#ifndef TWOTOFIVESPINNER_HPP
#define TWOTOFIVESPINNER_HPP

#include "Spinner.hpp"

/**
 * @brief An inherited class that applies polymorphism on spin functionality depending on players stakes within the range 2-5
 */
class FiveSpinner : public Spinner {
  //override function for spin
  int spin() override;
};

#endif
