/**
 * payout.hpp created by Nikita Evtushenko (nikita.evtushenko@uleth.ca) on 2024-09-29
 */

#include <iostream>
#include <string>

#ifndef PAYOUT_HPP
#define PAYOUT_HPP

class Payout {
    public: 
    Payout(); // I'm not so sure we need this. for payout
    virtual ~Payout(); // I'm not so sure we need this. for payout
    int amout;
    int payoutmultiplier;
    int calculatePayout(int playerScore);
};

#endif