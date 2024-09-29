#include <gtest/gtest.h>
#include "../include/solution.h"

// Тест конструктора по умолчанию
TEST(FiveTest, DefaultConstructor) {
    Five f;
    EXPECT_EQ(f.Size(), 0);
    EXPECT_EQ(f.Capacity(), 0);
}

// Тест конструктора с параметрами
TEST(FiveTest, ConstructorWithParameters) {
    Five f(5, '3');
    EXPECT_EQ(f.Size(), 5);
    EXPECT_EQ(f.Capacity(), 5);
    EXPECT_EQ(f.toString(), "33333");
}

// Тест конструктора копирования
TEST(FiveTest, CopyConstructor) {
    Five original(4, '2');
    Five copy(original);
    EXPECT_EQ(copy.Size(), 4);
    EXPECT_EQ(copy.toString(), "2222");
}

// Тест конструктора перемещения
TEST(FiveTest, MoveConstructor) {
    Five original(3, '1');
    Five moved(std::move(original));
    EXPECT_EQ(moved.Size(), 3);
    EXPECT_EQ(moved.toString(), "111");
    EXPECT_EQ(original.Size(), 0); // Ожидаем, что оригинал будет очищен
}

// Тест конструктора со строкой
TEST(FiveTest, ConstructorWithString) {
    std::string str = "1234";
    Five f(str);
    EXPECT_EQ(f.Size(), 4);
    EXPECT_EQ(f.toString(), "1234");
}

// Тест конструктора с initializer list
TEST(FiveTest, InitializerListConstructor) {
    Five f({1, 2, 3, 4, 0});
    EXPECT_EQ(f.Size(), 5);
    EXPECT_EQ(f.toString(), "04321"); // Ожидаем обратный порядок (если так сделано)
}

// Тест сложения
TEST(FiveTest, AdditionOperator) {
    Five f1(3, '2');  // 222
    Five f2(2, '3');  // 33
    Five result = f1 + f2;  // Ожидаем 305
    EXPECT_EQ(result.toString(), "310");
}

// Тест вычитания
TEST(FiveTest, SubtractionOperator) {
    Five f1(3, '4');  // 444
    Five f2(2, '3');  // 33
    Five result = f1 - f2;  // Ожидаем 411
    EXPECT_EQ(result.toString(), "411");
}

// Тест операции push_back
TEST(FiveTest, PushBack) {
    Five f(2, '1');
    f.push_back(3);
    EXPECT_EQ(f.Size(), 3);
    EXPECT_EQ(f.toString(), "311");
}

// Тест сравнения операторов
TEST(FiveTest, ComparisonOperators) {
    Five f1(2, '1');  // 11
    Five f2(2, '2');  // 22

    EXPECT_TRUE(f2 > f1);
    EXPECT_FALSE(f1 > f2);
    EXPECT_TRUE(f1 < f2);
    EXPECT_FALSE(f2 < f1);
    EXPECT_FALSE(f1 == f2);
    EXPECT_TRUE(f1 != f2);
}

// Тест очистки
TEST(FiveTest, Clear) {
    Five f(3, '4');
    f.Clear();
    EXPECT_EQ(f.Size(), 0);
    EXPECT_EQ(f.Capacity(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

