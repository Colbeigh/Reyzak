/**
 * @author Jem Pineda <j.pineda@uleth.ca>
 * @date Fall 2024
*/
#ifndef PWALLET_HPP_INCLUDED
#define PWALLET_HPP_INCLUDED

class PWallet {
 public:
PWallet();
~PWallet();
double checkBalance() const;
void removeZephy(double amount);
void addZephy(double amount);


 private:
double zephy;
};

#endif //PWALLET_HPP_INCLUDED
