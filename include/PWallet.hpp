/**
 * @author Jem Pineda <j.pineda@uleth.ca>
 * @date Fall 2024
*/
#ifndef PWALLET_HPP_INCLUDED
#define PWALLET_HPP_INCLUDED
/**
  * @class PWallet PWallet.cpp "PWallet.hpp"
  * @brief Handles the currency name Zephy
  */
class PWallet {
 public:
 /**
  * @brief A Default Constructor that initializes the currency
  */
PWallet();
/**
  * @brief Checks the current balance
  * @return the current balance
  */
double checkBalance() const;
/**
  * @brief Removes appropriate amount of Zephy 
  */
void removeZephy(double amount);
/**
  * @brief Adds appropriate amount of Zephy
  */
void addZephy(double amount);

 private:
double zephy;
};

#endif //PWALLET_HPP_INCLUDED
