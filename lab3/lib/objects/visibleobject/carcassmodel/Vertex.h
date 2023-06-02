#pragma once

#include "matrix.h"

class Vertex
{
public:
    Vertex() = default;
    Vertex(const double x, const double y, const double z);

    Vertex(const Vertex &point) = default;
    Vertex(const Vertex &&point) noexcept;

    Vertex &operator=(const Vertex &point) = default;
    Vertex &operator=(Vertex &&point) noexcept;

    ~Vertex() = default;

    double getX() const noexcept;
    double getY() const noexcept;
    double getZ() const noexcept;

    void setX(double const x);
    void setY(double const y);
    void setZ(double const z);

    bool operator==(const Vertex &point) const noexcept;
    bool isEqual(const Vertex &point) const noexcept;

    bool operator!=(const Vertex &point) const noexcept;
    bool isNotEqual(const Vertex &point) const noexcept;

    Vertex operator+(const Vertex &point)  const;
    Vertex operator-(const Vertex &point)  const;

    Vertex getAbsVertex(const Vertex &center);

    Vertex getCenter() const;
    void transform(const Matrix<double> &mat);

private:
    double m_x;
    double m_y;
    double m_z;
};
