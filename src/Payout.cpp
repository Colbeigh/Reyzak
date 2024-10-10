/**
 * Payout.cpp create by Nikita Evtushenko (nikita.evtushenko@uleth.ca) on 2024-09-29
 * @author Nikita Evtushenko
 * @date 2024-09-29
*/
#include "Payout.hpp"

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

Payout::~Payout() {}

double Payout::calculatePayout(int playerScore, double betAmout) {
    auto it = mapPayout.find(playerScore);

    if (it != mapPayout.end()) {
        double multiplayer = it -> second;
        double payout = betAmout * multiplayer;

        std::cout << "The payout amount is: " << payout << std::endl;

        return payout;

    } else {
        std::cout << "No payout Player Score is: " << playerScore << std::endl;
        return 0.0;
    }
}
