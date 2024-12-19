/**
 * @author Todd Across The Mountain [t.acrossthemountain@uleth.ca]
 * @date 2024-10
 */

#ifndef SPINNER_H
#define SPINNER_H

#include "MakeRandomInt.hpp"
#include <iostream>
#include <string>

/**
 * @brief a base class for Spinner Objects
 */
class Spinner {
 public:
    /**
     * @brief Constructor
     */
  Spinner();

  virtual ~Spinner();

   /**
     * @brief Pure virtual function for the spin method
     */
  virtual int Spin(std::string Stakes) = 0;
   /**
    * @brief Pure virtual function for the LowStakes Method
    */
  virtual int LowStakes(int NumberGuessed) = 0;
   /**
    * @brief Pure virtual function for the HighStakes method
    */
  virtual int HighStakes(int NumberGuessed) = 0;
};

#endif
