#pragma once

#include "IFigureValidator.h"
#include "TriangleValidator.h"
#include "SquareValidator.h"
#include "OctagonValidator.h"

class FigureValidator {
public:
    static void validateFigure(const IFigureValidator* validator, const std::vector<Point>& points);
};
