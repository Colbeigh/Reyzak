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
}

TEST(TestPlayer, BustTest) {
    Player Steve;
    Steve.currentscore = 17;
    EXPECT_TRUE(Steve.Bust());
    Steve.currentscore = 18;
    EXPECT_TRUE(Steve.Bust());
    Steve.currentscore = 16;
    EXPECT_FALSE(Steve.Bust());
}
TEST(TestPlayer, getBalanceTest) {
    Player Steve;
    EXPECT_EQ(Steve.getBalance(), 50);
}

TEST(TestPlayer, getpayoutTest) {
    Player Steve;
    Steve.currentscore = 0;
    Steve.currentbet = 0;
    EXPECT_EQ(Steve.getpayoutTest(), 50);
}
