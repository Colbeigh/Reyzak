/**
 * @author Todd Across The Mountain [t.acrossthemountain@uleth.ca]
 * @date 2024-10
 */
#include "gtest/gtest.h"

#include "2to5_Spinner.hpp"

TEST(TestFiveSpinner, TestSpinRange) {
    FiveSpinner Spinner;
    int result = Spinner.spin("NONE");
    EXPECT_LE(result, 5); //verify our result is less than 5
    EXPECT_GE(result, 2); //verify our result is greater than 2
}

TEST(TestFiveSpinner, TestHighStakesBias) {
    FiveSpinner Spinner;
    int result = Spinner.LowStakes(4);

    EXPECT_LT(result, 4); //verify our result is less than 4
    EXPECT_GT(result, 1); //verify our result is greater than 1
}
