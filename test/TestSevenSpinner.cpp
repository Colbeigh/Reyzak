/**
 * @author Todd Across The Mountain [t.acrossthemountain@uleth.ca]
 * @date 2024-10
 */
#include "gtest/gtest.h"

#include "0to7_Spinner.hpp"

TEST(TestSevenSpinner, TestSpinRange) {
    SevenSpinner Spinner;
    int result = Spinner.spin("NONE");
    EXPECT_LE(result, 7); //verify our result is less than 7
    EXPECT_GE(result, 0); //verify our result is greater than 0
}
