/**
 * payout.hpp created by Nikita Evtushenko (nikita.evtushenko@uleth.ca) on 2024-09-29
 */

#include <iostream>
#include <map>
#ifndef PAYOUT_HPP_INCLUDED 
#define PAYOUT_HPP_INCLUDED

class Payout {
    public: 
    Payout(); 
    virtual ~Payout(); // I'm not so sure we need this. for payout
    std::map<int, float> mapPayout; 
    int amount; // Dont think we need this
    int payoutmultiplier; // dont think we need this 
    double calculatePayout(int playerScore, int betAmout);
};

#endif
