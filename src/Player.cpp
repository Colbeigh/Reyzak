/**
Author: Jem Pineda
Dates:

 */
/**
want:
To use payout class to calculate
getBalance function


 */

#include <iostream>
#include "PWallet.hpp"
#include "Player.hpp"
#include "Payout.hpp"

//Parameters: 
Player::Player(){
}

//Parameters, 
void Player:: placeBet(){

currentbet = 0.0;

currentscore = 0;

static_cast<double>(currentbet);

std::cout << "Place your bet:";

std::cin >> currentbet;

if(currentbet < 0){

 std::cout << "Invalid Entry" << std::endl;

}
else if(currentbet > Wallet.checkBalance()){

    std::cout << "Insufficient Funds" << std::endl;
}
else 
{
std::cout << "You've placed: $" << currentbet << "to bet!\n";

Wallet.removeZephy(currentbet);

}
}


bool Player::Bust(){

if(currentScore >= 17){

return true;

}

else return false;

}

double Player::getBalance(){

    return Wallet.checkBalance();
}


void Player::Payout(){
    return Pay.calculatePayout(currentscore, currentbet);

}