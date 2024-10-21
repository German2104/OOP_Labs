#include "../include/square.h"
#include "../include/SquareValidator.h"

Square::Square(const std::vector<Point>& points) : Figure(points) {}

Square& Square::operator=(const Figure& other) {
    if (this != &other) {
        const auto* otherSquare = dynamic_cast<const Square*>(&other);
        if (otherSquare) {
            _points.clear();
            _points = other.getPoints();
        } else {
            throw std::invalid_argument("Invalid assignment. Expected Figure to be a Square.");
        }
    }
    return *this;
}

Square& Square::operator=(Figure&& other) {
    Square* otherSquare = dynamic_cast<Square*>(&other);
    if (otherSquare) {
        _points = std::move(otherSquare->_points);
    } else {
        throw std::invalid_argument("Invalid move assignment. Expected Figure to be a Square.");
    }

    return *this;
}

bool Square::operator==(const Figure& other) const {
    const Square* otherSquare = dynamic_cast<const Square*>(&other);
    if (otherSquare) {
        return _points == otherSquare->_points;
    }
    return false;
}

std::istream& Square::operator>>(std::istream& input) {
    _points.clear();
    for (int i = 0; i < 4; ++i) {
        Point point;
        input >> point;
        _points.push_back(point);
    }
    SquareValidator validator;
    FigureValidator::validateFigure(static_cast<const IFigureValidator*>(&validator), _points);
    return input;
}

double Square::area() const {
    return triangleArea(_points[0], _points[1], _points[2]) * 2; // Площадь квадрата = две площади треугольников
}

Point Square::getCenter() const {
    double centerX = 0.0;
    double centerY = 0.0;

    for (const Point& point : _points) {
        centerX += point.getX();
        centerY += point.getY();
    }

    centerX /= 4.0;
    centerY /= 4.0;

    return Point(centerX, centerY);
}

Square* Square::createSquare(const std::vector<Point>& points) {
    SquareValidator squareValidator;
    FigureValidator::validateFigure(static_cast<const IFigureValidator*>(&squareValidator), points);
    return new Square(points);
}
