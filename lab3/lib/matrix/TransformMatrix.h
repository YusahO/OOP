#pragma once

#include "matrix.h"

namespace TransformMatrix
{
    Matrix<double> createTranslationMatrix4(const double dx, const double dy, const double dz);
    Matrix<double> createRotationMatrix4(const double ax, const double ay, const double az);
    Matrix<double> createScalingMatrix4(const double kx, const double ky, const double kz);
}
