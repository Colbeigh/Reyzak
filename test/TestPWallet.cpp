/**
 * @author Jem Pineda <j.pineda@uleth.ca>
 * @date Fall 2024
*/
#include "gtest/gtest.h"
#include "PWallet.hpp"

TEST(TestPWallet, defaultConstructorTest) {
    PWallet Wallet;
    EXPECT_EQ(Wallet.zephy, 50);
}

TEST(TestPWallet, checkBalanceTest) {
    PWallet Wallet;
    EXPECT_EQ(Wallet.checkBalance(), 50);
}

TEST(TestPWallet, addZephyTest) {
    PWallet Wallet;
    EXPECT_EQ(Wallet.addZephy(0), 50);
    EXPECT_EQ(Wallet.addZephy(10), 60);
}

TEST(TestPWallet, removeZephyTest) {
    PWAllet Wallet;
    EXPECT_EQ(Wallet.removeZephy(0), 50);
    EXPECT_EQ(Wallet.removeZephy(10), 40);
}
