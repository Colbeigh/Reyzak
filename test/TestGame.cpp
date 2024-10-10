#include <gtest/gtest.h>
#include "Game.hpp"
#include "Player.hpp"  // Ensure you include the Player's header
#include "Spinner.hpp" // Ensure you include the Spinner's header
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
    game.Stakes(10); // Test with a low bet
    EXPECT_EQ(game.stakes, "Low");
}

TEST(TestGame, TestStakesMedium) {
    Game game;
    game.Stakes(30); // Test with a medium bet
    EXPECT_EQ(game.stakes, "Medium");
}

TEST(TestGame, TestStakesHigh) {
    Game game;
    game.Stakes(50); // Test with a high bet
    EXPECT_EQ(game.stakes, "High");
}

TEST(TestGame, TestPlayerPayout) {
    Game game;
    game.player.currentscore += 30; // Simulating a spin that wins
    game.player.currentbet = 20; // Set bet
    game.player.getPayout();
    EXPECT_GT(game.player.getBalance(), 50);
}

TEST(TestGame, TestExitWithNoBalance) {
    Game game;
    game.player.currentscore = 0; // Set current score to 0
    game.player.currentbet = 50; // Bet the entire balance
    game.player.getPayout(); // Simulate the payout
    std::ostringstream output; // Capture output
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    game.Exit(); // Call Exit

    std::cout.rdbuf(oldCout); // Reset cout
    EXPECT_TRUE(output.str().find("Better luck next time") != std::string::npos);
}

TEST(TestGame, TestExitWithProfit) {
    Game game;
    game.player.currentscore += 60; // Simulate winning score
    std::ostringstream output; // Capture output
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    game.Exit(); // Call Exit

    std::cout.rdbuf(oldCout); // Reset cout
    EXPECT_TRUE(output.str().find("You made a $") != std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

