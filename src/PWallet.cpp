// Minimal source file for a placebo class that does nothing but allows the
// pipeline to pass.

#include "PWallet.hpp"
#include <iostream>

PWallet::PWallet() {
zephy = 50;
}

double PWallet::checkBalance() const {
return zephy;
}

void PWallet::addZephy(double amount) {
if(amount < 0) {
    std::cout << "Invalid number" << std::endl;
} else {zephy += amount;}
}

void PWallet::removeZephy(double amount) {
if(amount < 0) {
    std::cout << "Invalid number\n";
} else if(amount > zephy) {
    std::cout << "Insufficient funds" << std::endl;
} else{zephy -= amount;}
}