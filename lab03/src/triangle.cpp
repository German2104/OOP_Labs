#include "../include/triangle.h"

Triangle::Triangle(const std::vector<Point>& points) : Figure(points) {}

Triangle& Triangle::operator=(const Figure& other) {
    if (this != &other) {
        const auto* otherTriangle = dynamic_cast<const Triangle*>(&other);
        if (otherTriangle) {
            _points.clear();
            _points = other.getPoints();
        } else {
            throw std::invalid_argument("Invalid assignment. Expected Figure to be a Triangle.");
        }
    }
    return *this;
}

Triangle& Triangle::operator=(Figure&& other) {
    Triangle* otherTriangle = dynamic_cast<Triangle*>(&other);
    if (otherTriangle) {
        _points = std::move(otherTriangle->_points);
    } else {
        throw std::invalid_argument("Invalid move assignment. Expected Figure to be a Triangle.");
    }

    return *this;
}

bool Triangle::operator==(const Figure& other) const {
    const Triangle* otherTriangle = dynamic_cast<const Triangle*>(&other);
    if (otherTriangle) {
        return _points == otherTriangle->_points;
    }
    return false;
}

std::istream& Triangle::operator>>(std::istream& input) {
    _points.clear();
    for (int i = 0; i < 3; ++i) {
        Point point;
        input >> point;
        _points.push_back(point);
    }
    TriangleValidator validator;
    FigureValidator::validateFigure(static_cast<const IFigureValidator*>(&validator), _points);
    return input;
}

double Triangle::area() const {
    return triangleArea(_points[0], _points[1], _points[2]);
}

Point Triangle::getCenter() const {
    double centerX = 0.0;
    double centerY = 0.0;

    for (const Point& point : _points) {
        centerX += point.getX();
        centerY += point.getY();
    }

    centerX /= 3.0;
    centerY /= 3.0;

    return Point(centerX, centerY);
}

Triangle* Triangle::createTriangle(const std::vector<Point>& points) {
    TriangleValidator triangleValidator;
    FigureValidator::validateFigure(static_cast<const IFigureValidator*>(&triangleValidator), points);
    return new Triangle(points);
}
