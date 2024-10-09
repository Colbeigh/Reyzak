#include "gtest/gtest.h"
#include "Payout.hpp"

TEST(PayoutTest, testPayout) {
    Payout p;
    EXPECT_EQ(0, p.calculatePayout(0, 0));
}

TEST(PayoutTest, testPayout2) {
    Payout p;
    EXPECT_EQ(5, p.calculatePayout(12, 20));
}

TEST(PayoutTest, testPayout3) {
    Payout p;
    EXPECT_EQ(10, p.calculatePayout(13, 20));
}

TEST(PayoutTest, testPayout4) {
    Payout p;
    EXPECT_EQ(20, p.calculatePayout(14, 20));
}

TEST(PayoutTest, testPayout5) {
    Payout p;
    EXPECT_EQ(25, p.calculatePayout(15, 20));
}

TEST(PayoutTest, testPayout6) {
    Payout p;
    EXPECT_EQ(30, p.calculatePayout(16, 20));
}

TEST(PayoutTest, testPayout7) {
    Payout p;
    EXPECT_EQ(40, p.calculatePayout(17, 20));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}




