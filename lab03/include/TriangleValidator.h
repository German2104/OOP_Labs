#pragma once

#include "IFigureValidator.h"

class TriangleValidator : public IFigureValidator {
public:
    void validate(std::vector<Point>& points) const override;
};