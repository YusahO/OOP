#pragma once

#include "matrix.h"

class TransformMatrix4
{
public:
    static Matrix<float> createTranslationMatrix4(const double dx, const double dy, const double dz);
    static Matrix<float> createRotationMatrix4(const double ax, const double ay, const double az);
    static Matrix<float> createScalingMatrix4(const double kx, const double ky, const double kz);

private:
    static std::array<std::array<double, 4>, 4>
};
