/**
 * @author Todd Across The Mountain [t.acrossthemountain@uleth.ca]
 * @date 2024-10
 */
#include "gtest/gtest.h"

#include "2to5_Spinner.hpp"

TEST(TestFiveSpinner, TestSpinRange) {
    FiveSpinner Spinner;
    int result = Spinner.spin("NONE");
    EXPECT_LE(result, 5);
    EXPECT_GE(result, 2);
}