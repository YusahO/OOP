#pragma once

#include "BaseTransformer.h"

class Transformer : public BaseTransformer
{
public:
    Transformer();
    void transform(Vertex &vert) override;

    void setTranslationMatrix(const double dx, const double dy, const double dz);
    void setRotationMatrix(const double ax, const double ay, const double az);
    void setScalingMatrix(const double kx, const double ky, const double kz);

protected:

    Matrix<double> m_matrix;
};
