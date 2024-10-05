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

double amount = 0.0;

int currentScore = 0;

static_cast<double>(amount);

std::cout << "Place your bet:";

std::cin >> amount;

if(amount < 0){

 std::cout << "Invalid Entry" << std::endl;

}
else if(amount > Wallet.checkBalance()){

    std::cout << "Insufficient Funds" << std::endl;
}
else 
{
currentBet = amount;

std::cout << "You've placed: $" << currentBet

 << "to bet!" << std::endl;

Wallet.removeZephy(amount);
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


void Player::payout(){


}