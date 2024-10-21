#pragma once

#include "figure.h"
#include "FigureValidator.h"
#include "SquareValidator.h"

class Square : public Figure {
public:
    Square(const std::vector<Point>& points);

    Square& operator=(const Figure& other) override;

    Square& operator=(Figure&& other) override;

    bool operator==(const Figure& other) const override;

    std::istream& operator>>(std::istream& input) override;

    double area() const override;

    Point getCenter() const override;

    static Square* createSquare(const std::vector<Point>& points);
};
