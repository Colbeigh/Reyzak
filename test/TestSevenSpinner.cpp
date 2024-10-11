/**
 * @author Todd Across The Mountain [t.acrossthemountain@uleth.ca]
 * @date 2024-10
 */
#include "gtest/gtest.h"

#include "0to7_Spinner.hpp"

TEST(TestSevenSpinner, TestSpinRange) {
    SevenSpinner Spinner;
    for (int i = 0; i < 10; i++) {
        int result = Spinner.spin("NONE");
        EXPECT_LE(result, 7); 
        EXPECT_GE(result, 0); 
    }
}

TEST(TestSevenSpinner, TestHighStakesMultipleSpins) {
    SevenSpinner Spinner;
    for (int i = 0; i < 10; i++) {
        int result = Spinner.spin("High");
        EXPECT_LE(result, 7); 
        EXPECT_GE(result, 0); 
    }
}

TEST(TestSevenSpinner, TestLowStakesMultipleSpins) {
    SevenSpinner Spinner;
    for (int i = 0; i < 10; i++) {
        int result = Spinner.spin("Low");
        EXPECT_LE(result, 7); 
        EXPECT_GE(result, 0); 
    }
}

TEST(TestSevenSpinner, TestHighStakesBias) {
    SevenSpinner Spinner;
    int result = Spinner.HighStakes(4);

    EXPECT_LE(result, 7); 
    EXPECT_GT(result, 4); 

    int result2 = Spinner.HighStakes(0);
    EXPECT_LE(result2, 3); 
    EXPECT_GT(result2, 0); 

    int result3 = Spinner.HighStakes(6);
    EXPECT_EQ(result3, 6);
}

TEST(TestSevenSpinner, TestLowStakesBias) {
    SevenSpinner Spinner;
    int result = Spinner.LowStakes(4);

    EXPECT_LT(result, 4);
    EXPECT_GE(result, 1);

    int result2 = Spinner.LowStakes(7);

    EXPECT_LT(result2, 7);
    EXPECT_GE(result2, 4);

    int result3 = Spinner.LowStakes(3);
    EXPECT_EQ(result3, 3);
}
