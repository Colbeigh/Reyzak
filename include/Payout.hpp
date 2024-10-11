/**
 * Payout.hpp Nikita Evtushenko (nikita.evtushenko@uleth.ca) on 2024-09-29
 * @author Nikita Evtushenko
 * @date 2024-09-29
 */

#include <iostream>
#include <map>
#ifndef PAYOUT_HPP_INCLUDED
#define PAYOUT_HPP_INCLUDED
 /**
    * @brief a class to calculate the payout 
    * @details makes a map to have preset calculation percentages
    * has a function called calculatePayout that takes in playerScore and betAmount
    * from Player.hpp 
    */
class Payout {
 public:
    /**
     * @brief Default constructor for Payout.
    */
    Payout();

    /**
     * @brief Destructor
    */
    virtual ~Payout();

    /**
     * @brief create a key value pair of integer and floats 
     * the ints are the playerScore and floats are the payout %
    */
    std::map<int, float> mapPayout;

    /**
     * @brief calculatePayout takes the playerScore and betAmout 
     * and compares with the keys to see if the result is correct
     * @param playerScore int
     * @param betAmout double
    */
    double calculatePayout(int playerScore, double betAmout);
};

#endif
