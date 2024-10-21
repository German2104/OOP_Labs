#pragma once

#include "IFigureValidator.h"

class SquareValidator : public IFigureValidator {
public:
    void validate(std::vector<Point>& points) const override;
};