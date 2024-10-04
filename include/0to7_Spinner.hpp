#ifndef ZEROTOSEVENSPINNER_H
#define ZEROTOSEVENSPINNER_H

#include "Spinner.hpp"
#include <iostream>
#include <string>

/**
 * @brief an inherited class that applies polymorphism on spin functionality depending on players bets within the range 0-7
 */
class SevenSpinner : public Spinner {
  int spin(std::string Stakes) override;
};

#endif
