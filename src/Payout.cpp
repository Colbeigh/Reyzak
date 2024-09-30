#include "Payout.hpp"

Payout::Payout() {}; // Don't know if we need this for payout

Payout::~Payout() {}; // Don't know if we need this for payout

int Payout::calculatePayout(int playerScore) {
return playerScore + (amout * (payoutmultiplier / 100));
};