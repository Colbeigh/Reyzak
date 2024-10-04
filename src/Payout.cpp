#include "Payout.hpp"
#include <iostream>

Payout::Payout() {
    mapPayout = {
        {12, 0.25},
        {13, 0.50},
        {14, 1.00},
        {15, 1.25},
        {16, 1.50},
        {17, 2.00}
    };
}

Payout::~Payout() {}; // Don't know if we need this for payout

int Payout::calculatePayout(int playerScore, int betAmout) {

    auto it = mapPayout.find(playerScore);

    if (it != mapPayout.end()) {
        
        double multiplayer = it -> second;
        int payout = betAmout * multiplayer;

        std::cout << "The payout Amount" << payout << std::endl;

        return payout;

    } else { 
        std::cout << "No payout Player Score is: " << playerScore << std::endl;
    }

    
    
};
