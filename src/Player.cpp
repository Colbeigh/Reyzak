/**
 * @author Jem Pineda <j.pineda@uleth.ca>
 * @date Fall 2024
*/
#include "Player.hpp"

//Parameters:
Player::Player() {
currentbet = 0.0;
currentscore = 0;
PWallet Wallet;
}

//Parameters
void Player:: placeBet() {
currentbet = 0.0;
currentscore = 0;

while(true) {
std::cout << "Place your bet:";
std::cin >> currentbet;
if(std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<
    std::streamsize>::max(), '\n');
    std::cout <<"Invalid, Please enter a number\n";
} else if (currentbet < 0) {
    std::cout << "Invalid Entry" << std::endl;
} else if (currentbet > Wallet.checkBalance()) {
    std::cout << "Insufficient Funds" << std::endl;
} else {
std::cout << "You've placed: $" << currentbet << " to bet!\n";
Wallet.removeZephy(currentbet);
break;
}
}
}

bool Player::Bust() {
if(currentscore >= 17) {
return true;
} else {return false;
}
}

double Player::getBalance() {
    return Wallet.checkBalance();
}


void Player::getPayout() {
    currentbet = Pay.calculatePayout(currentscore, currentbet);
    if (currentbet > 0) {
        Wallet.addZephy(currentbet);
        std::cout << "Your new balance is $" << Wallet.checkBalance() << "/n";
    }
}
