#ifndef TWOTOFIVESPINNER_HPP
#define TWOTOFIVESPINNER_HPP

#include "Spinner.hpp"

/**
 * @brief An inherited class that applies spin functionality depending on players stakes
 */
class FiveSpinner : public Spinner {
    //override function for spin
    int spin();
};

#endif
