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
        EXPECT_LE(result, 7); //verify our result is less than 7
        EXPECT_GE(result, 0); //verify our result is greater than 0
    }
}

TEST(TestSevenSpinner, TestHighStakesMultipleSpins) {
    SevenSpinner Spinner;
    for (int i = 0; i < 10; i++) {
        int result = Spinner.spin("High");
        EXPECT_LE(result, 7); //verify our result is less than 7
        EXPECT_GE(result, 0); //verify our result is greater than 0
    }
}

TEST(TestSevenSpinner, TestLowStakesMultipleSpins) {
    SevenSpinner Spinner;
    for (int i = 0; i < 10; i++) {
        int result = Spinner.spin("Low");
        EXPECT_LE(result, 7); //verify our result is less than 7
        EXPECT_GE(result, 0); //verify our result is greater than 0
    }
}
