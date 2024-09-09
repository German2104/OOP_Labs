#include <gtest/gtest.h>
#include <string>
#include "../include/solution.h"

TEST(SolutionTest, BasicCases) {
    EXPECT_EQ(solution("abc"), "bac");
    EXPECT_EQ(solution("aabacbaa"), "bbabcabb");
}

TEST(SolutionTest, EdgeCases) {
    EXPECT_EQ(solution(""), "");  // Пустая строка
    EXPECT_EQ(solution("a"), "b");  // Одна 'a'
    EXPECT_EQ(solution("b"), "a");  // Одна 'b'
    EXPECT_EQ(solution("ab"), "ba");  // Одна 'a' и одна 'b'
    EXPECT_EQ(solution("ba"), "ab");  // Перевернутая версия
    EXPECT_EQ(solution("c"), "c");    // Одна 'c'
    EXPECT_EQ(solution("ccccc"), "ccccc");  // Только 'c'
}

TEST(SolutionTest, RandomCases) {
    EXPECT_EQ(solution("abracadabra"), "barbcbdbarb");
    EXPECT_EQ(solution("ababababab"), "bababababa");
    EXPECT_EQ(solution("bbaaaabbaa"), "aabbbbaabb");
}

TEST(SolutionTest, NoReplacements) {
    EXPECT_EQ(solution("cdefg"), "cdefg");  // Строка без 'a' и 'b'
    EXPECT_EQ(solution("xyz"), "xyz");
    EXPECT_EQ(solution("1234567890"), "1234567890");
}

TEST(SolutionTest, UniformStrings) {
    EXPECT_EQ(solution("aaaaaa"), "bbbbbb");  // Только 'a'
    EXPECT_EQ(solution("bbbbbb"), "aaaaaa");  // Только 'b'
    EXPECT_EQ(solution("cccccc"), "cccccc");  // Только 'c'
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}