// Minimal source file for a placebo class that does nothing but allows the
// pipeline to pass.

#include "PWallet.hpp"
#include <iostream>

PWallet::PWallet(double &zephy){
zephy = 50;
*currentZephy = zephy;
}

double PWallet::checkBalance(){

return *currentZephy;
}

void PWallet::addZephy(double amount){

if(amount < 0){
    std::cout << "Invalid number" << std::endl;

}
else {
*currentZephy =+ amount;

}
}

void PWallet::removeZephy(double amount){

if(amount > *currentZephy){
    std::cout <<"nope" << std::endl;
}    
else{
    *currentZephy =- amount;
}
}