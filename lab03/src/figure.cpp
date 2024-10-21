#include "../include/figure.h"
#include "../include/square.h"
#include "../include/triangle.h"
#include "../include/octagon.h"

Figure::Figure() {}

Figure::Figure(const std::vector<Point>& points) : _points(points) {}

std::vector<Point> Figure::getPoints() const {
    return _points;
}

std::ostream& operator<<(std::ostream& out, const Figure& figure) {
    for (const Point& point: figure._points) {
        out << point << std::endl;
    }
    return out;
}

Figure::operator double() const {
    return area();
}

Figure* Figure::createFigureWithPoints(const std::vector<Point>& points) {
    if (points.size() == 3) {
        return Triangle::createTriangle(points);
    } else if (points.size() == 4) {
        return Square::createSquare(points);
    } else if (points.size() == 8) {
        return Octagon::createOctagon(points);
    } else {
        throw std::invalid_argument("Unsupported number of points for creating a figure.");
    }
}

double Figure::triangleArea(const Point& point1, const Point& point2, const Point& point3) const {
    double a = point1.distanceBetweenPoints(point2);
    double b = point2.distanceBetweenPoints(point3);
    double c = point3.distanceBetweenPoints(point1);
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
