#include <gtest/gtest.h>
#include "../include/solution.h"

// Тест 1: Проверяем размер 2x1
TEST(MinimalCutsTest, Size2x1) {
    EXPECT_EQ(minimalCuts(2, 1), 1);
}

// Тест 2: Проверяем размер 3x1
TEST(MinimalCutsTest, Size3x1) {
    EXPECT_EQ(minimalCuts(3, 1), 2);
}

// Тест 3: Проверяем размер 3x3
TEST(MinimalCutsTest, Size3x3) {
    EXPECT_EQ(minimalCuts(3, 3), 8);
}

// Тест 4: Некорректные данные (одна из сторон равна 0)
TEST(MinimalCutsTest, InvalidInput) {
    EXPECT_EQ(minimalCuts(0, 5), 0);
    EXPECT_EQ(minimalCuts(4, 0), 0);
    EXPECT_EQ(minimalCuts(-1, 5), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}