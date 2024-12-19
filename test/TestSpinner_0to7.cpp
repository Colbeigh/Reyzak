/**
 * @author Todd Across The Mountain [t.acrossthemountain@uleth.ca]
 * @date 2024-10
 */
#include "gtest/gtest.h"

#include "Spinner_0to7.hpp"

TEST(TestSpinner_0to7, TestSpinRange) {
    Spinner_0to7 Spinner;
    for (int i = 0; i < 10; i++) {
        int result = Spinner.Spin("NONE");
        EXPECT_LE(result, 7);
        EXPECT_GE(result, 0);
    }
}

TEST(TestSpinner_0to7, TestHighStakesMultipleSpins) {
    Spinner_0to7 Spinner;
    for (int i = 0; i < 10; i++) {
        int result = Spinner.Spin("High");
        EXPECT_LE(result, 7);
        EXPECT_GE(result, 0);
    }
}

TEST(TestSpinner_0to7, TestLowStakesMultipleSpins) {
    Spinner_0to7 Spinner;
    for (int i = 0; i < 10; i++) {
        int result = Spinner.Spin("Low");
        EXPECT_LE(result, 7);
        EXPECT_GE(result, 0);
    }
}

TEST(TestSpinner_0to7, TestHighStakesBias) {
    Spinner_0to7 Spinner;
    int result = Spinner.HighStakes(4);

    EXPECT_LE(result, 7);
    EXPECT_GT(result, 4);

    int result2 = Spinner.HighStakes(0);
    EXPECT_LE(result2, 3);
    EXPECT_GT(result2, 0);

    int result3 = Spinner.HighStakes(6);
    EXPECT_EQ(result3, 6);
}

TEST(TestSpinner_0to7, TestLowStakesBias) {
    Spinner_0to7 Spinner;
    int result = Spinner.LowStakes(4);

    EXPECT_LT(result, 4);
    EXPECT_GE(result, 1);

    int result2 = Spinner.LowStakes(7);

    EXPECT_LT(result2, 7);
    EXPECT_GE(result2, 4);

    int result3 = Spinner.LowStakes(3);
    EXPECT_EQ(result3, 3);
}
