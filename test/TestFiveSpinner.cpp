/**
 * @author Todd Across The Mountain [t.acrossthemountain@uleth.ca]
 * @date 2024-10
 */
#include "gtest/gtest.h"

#include "2to5_Spinner.hpp"

TEST(TestFiveSpinner, TestSpinRange) {
    FiveSpinner Spinner;
    for (int i = 0; i < 10; i++) {
        int result = Spinner.spin("NONE");
        EXPECT_LE(result, 5);
        EXPECT_GE(result, 2);
    }
}

TEST(TestFiveSpinner, TestLowStakesBias) {
    FiveSpinner Spinner;
    int result = Spinner.LowStakes(4);

    EXPECT_LT(result, 4);
    EXPECT_GT(result, 1);

    int result2 = Spinner.LowStakes(5);

    EXPECT_LT(result2, 5);
    EXPECT_GT(result2, 2);
}

TEST(TestFiveSpinner, TestHighStakesBias) {
    FiveSpinner Spinner;
    int result = Spinner.HighStakes(3);

    EXPECT_LE(result, 5);
    EXPECT_GT(result, 3);

    int result2 = Spinner.HighStakes(2);
    EXPECT_LT(result2, 5);
    EXPECT_GT(result2, 2);

    int result3 = Spinner.HighStakes(4);
    EXPECT_EQ(result3, 4);
}
TEST(TestFiveSpinner, TestHighStakesMultipleSpins) {
    FiveSpinner Spinner;
    for (int i = 0; i < 10; i++) {
        int result = Spinner.spin("High");
        EXPECT_LE(result, 5);
        EXPECT_GE(result, 2);
    }
}

TEST(TestFiveSpinner, TestLowStakesMultipleSpins) {
    FiveSpinner Spinner;
    for (int i =0; i <10; i++) {
        int result = Spinner.spin("Low");
        EXPECT_LE(result, 5);
        EXPECT_GE(result, 2);
    }
}
