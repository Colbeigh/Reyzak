// Minimal source file for a placebo class that does nothing but allows the
// pipeline to pass.

#ifndef PWALLET_HPP_INCLUDED
#define PWALLET_HPP_INCLUDED

class PWallet {
 public:

PWallet();
PWallet(double &zephy);
double checkBalance();
void removeZephy(double amount);
void addZephy(double amount);


private:

double* currentZephy;

};

#endif //PWALLET_HPP_INCLUDED
