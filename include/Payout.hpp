/**
 * payout.hpp created by Nikita Evtushenko (nikita.evtushenko@uleth.ca) on 2024-09-29
 */

#include <iostream>
#include <string>


class Payout {
    public: 
    int amout;
    int payoutmultiplier;

    int calculatePayout(int playerScore) { 
        /**
         * To calculate the payout we need to first 
         * get the amount we trying to calculate
         * get the multiplier from the spinner for the payout
         * then also get the "playersScore" the player cashout amount EX. if  player cashout at $20 the payout of $20 might be 5% so the payout is $1 which bring the total playerscore to $21.
         */

        playerScore +=  amout * (payoutmultiplier / 100);
        return playerScore;
        

    }

};