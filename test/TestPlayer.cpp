/**
 * @author Jem Pineda <j.pineda@uleth.ca>
 * @date Fall 2024
*/
#include "gtest/gtest.h"
#include "Payout.hpp"
#include "PWallet.hpp"
#include <limits>
#include <iostream>
#include "Player.hpp"

TEST(TestPlayer, defaultConstructorTest) {
    Player Steve;
    EXPECT_EQ(Steve.currentbet, 0.0);
    EXPECT_EQ(Steve.currentscore, 0);
}

TEST(TestPlayer, placeBetTest) {
    Player Steve;
    Steve.placeBet();
    EXPECT_THROW("A", "Invalid, Please enter a number\n");
}

TEST(TestPlayer, BustTest) {
}
TEST(TestPlayer, getBalanceTest) {
}

TEST(TestPlayer, getpayoutTest) {
}
