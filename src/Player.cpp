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
Player::Player(int &pScore, double &pBet, PWallet Wallet){
pScore = 0;
pBet = 0;
*currentScore = pScore;
*currentBet = pBet; 

}
/**
 *
 *
 */
int Player::getScore(){
    if(*currentScore <= 0){
        std::cout << "Player currently has no scores" << endl;
    }
    else{
    return *currentScore;
}
return *currentScore;
}

//Parameters, interger amount for bet
void Player:: placeBet(double amount){

*currentBet =  static_cast<double>(amount);
std::cout << "Place your bet:";
std::cin >> amount;
if(Bet <= 0){
 cout << "???" << endl;
}
else if(amount > Wallet.checkBalance()){
    cout << "Insufficient Funds" << endl;
}
else 
{
*currentBet = amount;
cout << "You've placed: $" << currentBet << "to bet!" << endl;
Wallet.removeZephy(amount);
}
}

bool Player::Bust(){


}