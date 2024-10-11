/**
 * @author Jem Pineda <j.pineda@uleth.ca>
 * @date Fall 2024
*/
#include "gtest/gtest.h"
#include "PWallet.hpp"

TEST(TestPWallet, defaultConstructorTest) {
    PWallet Wallet;
    EXPECT_EQ(Wallet.checkBalance, 50);
}

TEST(TestPWallet, checkBalanceTest) {
    PWallet Wallet;
    EXPECT_EQ(Wallet.checkBalance(), 50);
}

TEST(TestPWallet, addZephyTest) {
    PWallet Wallet;
    Wallet.addZephy(0);
    EXPECT_EQ(Wallet.checkBalance(), 50);
    Wallet.addZephy(10);
    EXPECT_EQ(Wallet.checkBalance(), 60);
}

TEST(TestPWallet, removeZephyTest) {
    PWAllet Wallet;
    Wallet.removeZephy(0);
    EXPECT_EQ(Wallet.checkBalance(), 50);
    Wallet.removeZephy(10);
    EXPECT_EQ(Wallet.checkBalance(), 40);
}
