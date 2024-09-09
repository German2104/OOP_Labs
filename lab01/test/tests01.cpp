#include <gtest/gtest.h>
#include <string>
#include "../include/solution.h"

TEST(test_01, basic_test_set)
{
    ASSERT_EQ(solution("abc"), "bac");
}

TEST(test_02, basic_test_set)
{
    ASSERT_EQ(solution("aabacbaa"), "bbabcabb");
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}