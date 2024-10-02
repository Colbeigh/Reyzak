/**
Author: Jem Pineda
Dates:

 */
/**
want:
target in bool and player
current bet public
const static_cast from int to double


 */

#include <iostream>
#include "PWallet.hpp"
#include "Player.hpp"

//Parameters, Player 
Player::Player(int Pscore, int currentBet, PWallet Wallet){
Pscore = 0;
currentBet = 0;

}

//Parameters, interger amount for bet
Player:: placeBet(double currentBet){
/**
 * Steps:
 * Make static cast for amount
 * take money from amount place it on currentbet
 * check if they have enough
 * if not then warn
 * if 0 (??)
 * if there's money, check wallet then take from wallet
 * 
*/
double amount=  static_cast<double>(currentBet);
std::cout << "Place your bet:";
std::cin >> amount;
if(amount <= 0){
 cout << "???" << endl;
}
else if(amount > Wallet.checkBalance()){
    cout << "Insufficient Funds" << endl;
}
else 
{
currentBet = amount;
cout << "You've placed: $" << currentBet << "to bet!" << endl;
Wallet.removeZephy(amount);
}
}

Player::Bust(){

    
}