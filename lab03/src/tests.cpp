#include <gtest/gtest.h>
#include "../include/figure.h"
#include "../include/square.h"
#include "../include/triangle.h"
#include "../include/octagon.h"
#include <vector>

class FigureTestArea : public testing::TestWithParam<std::tuple<Figure*, double>> {
};

TEST_P(FigureTestArea, TestArea) {
    double expectedArea, shapeArea;

    auto params = GetParam();
    Figure* figure = std::get<0>(params);
    expectedArea = std::get<1>(params);

    shapeArea = figure->area();

    ASSERT_DOUBLE_EQ(expectedArea, shapeArea);
}

INSTANTIATE_TEST_SUITE_P(
        FigureAreaTestParameters,
        FigureTestArea,
        testing::Values(
                std::make_tuple(Square::createSquare(
                        {Point(0.0, 0.0), Point(2.0, 0.0), Point(2.0, 2.0), Point(0.0, 2.0)}), 4.0),
                std::make_tuple(Triangle::createTriangle(
                        {Point(0.0, 0.0), Point(1.0, 0.0), Point(0.5, 1.0)}), 0.5),
                std::make_tuple(Octagon::createOctagon(
                        {Point(0.0, 0.0), Point(3.0, 0.0), Point(4.0, 1.0), Point(4.0, 3.0), Point(3.0, 4.0),
                         Point(0.0, 4.0), Point(1.0, 3.0), Point(1.0, 1.0)}), 18.0)
        )
);

class FigureTestCenter : public testing::TestWithParam<std::tuple<Figure*, Point>> {
};

TEST_P(FigureTestCenter, TestCenter) {
    Point expectedCenter, shapeCenter;

    auto params = GetParam();
    Figure* figure = std::get<0>(params);
    expectedCenter = std::get<1>(params);

    shapeCenter = figure->getCenter();

    ASSERT_EQ(expectedCenter, shapeCenter);
}

INSTANTIATE_TEST_SUITE_P(
        FigureCenterTestParameters,
        FigureTestCenter,
        testing::Values(
                std::make_tuple(Square::createSquare(
                                        {Point(0.0, 0.0), Point(2.0, 0.0), Point(2.0, 2.0), Point(0.0, 2.0)}),
                                Point(1.0, 1.0)),
                std::make_tuple(Triangle::createTriangle(
                        {Point(0.0, 0.0), Point(1.0, 0.0), Point(0.5, 1.0)}), Point(0.5, 0.3333333333333333)),
                std::make_tuple(Octagon::createOctagon(
                        {Point(0.0, 0.0), Point(3.0, 0.0), Point(4.0, 1.0), Point(4.0, 3.0), Point(3.0, 4.0),
                         Point(0.0, 4.0), Point(1.0, 3.0), Point(1.0, 1.0)}), Point(2.0, 2.0))
        )
);

TEST(ConstructorTest, TestSquare) {
    std::vector<Point> invalidPoints = {Point(0.0, 0.0), Point(1.0, 0.0), Point(0.5, 0.5)};
    Square* square;
    ASSERT_THROW({
                     square = Square::createSquare(invalidPoints);
                 }, std::invalid_argument);
}

TEST(ConstructorTest, TestTriangle) {
    std::vector<Point> invalidPoints = {Point(0.0, 0.0), Point(1.0, 0.0)};
    Triangle* triangle;
    ASSERT_THROW({
                     triangle = Triangle::createTriangle(invalidPoints);
                 }, std::invalid_argument);
}

TEST(ConstructorTest, TestOctagon) {
    std::vector<Point> invalidPoints = {Point(0.0, 0.0), Point(1.0, 0.0), Point(1.5, 1.0)};
    Octagon* octagon;
    ASSERT_THROW({
                     octagon = Octagon::createOctagon(invalidPoints);
                 }, std::invalid_argument);
}



int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
