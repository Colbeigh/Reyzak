/**
 * main.cpp created by Colby Hanna (Colby.Hanna@uleth.ca) on 2024-09-29
 */
#include <gtest/gtest.h>
#include "Game.hpp"
#include "Player.hpp"
#include "Spinner.hpp"
#include <sstream>
#include <iostream>

TEST(TestGame, TestInitialScore) {
    Game game;
    EXPECT_EQ(game.player.currentscore, 0);
}

TEST(TestGame, TestInitialBalance) {
    Game game;
    EXPECT_EQ(game.player.getBalance(), 50);
}

TEST(TestGame, TestStakesLow) {
    Game game;
    game.Stakes(10);
    EXPECT_EQ(game.stakes, "Low");
}

TEST(TestGame, TestStakesMedium) {
    Game game;
    game.Stakes(30);
    EXPECT_EQ(game.stakes, "Medium");
}

TEST(TestGame, TestStakesHigh) {
    Game game;
    game.Stakes(50);
    EXPECT_EQ(game.stakes, "High");
}

TEST(TestGame, TestPlayerPayout) {
    Game game;
    game.player.currentscore += 17;
    game.player.currentbet = 20;
    game.player.getPayout();
    EXPECT_GT(game.player.getBalance(), 50);
}

TEST(TestGame, TestExitWithProfit) {
    Game game;
    game.player.currentscore += 17;
    game.player.currentbet = 50;
    game.player.getPayout();

    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    game.Exit()

    std::cout.rdbuf(oldCout);
    std::string expectedMessage = "You made a $";
    EXPECT_TRUE(output.str().find(expectedMessage) != std::string::npos);
}
