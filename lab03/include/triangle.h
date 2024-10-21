#pragma once

#include "figure.h"
#include "FigureValidator.h"
#include "TriangleValidator.h"

class Triangle : public Figure {
public:
    Triangle(const std::vector<Point>& points);

    Triangle& operator=(const Figure& other) override;

    Triangle& operator=(Figure&& other) override;

    bool operator==(const Figure& other) const override;

    std::istream& operator>>(std::istream& input) override;

    double area() const override;

    Point getCenter() const override;

    static Triangle* createTriangle(const std::vector<Point>& points);
};
