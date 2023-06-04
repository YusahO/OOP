#pragma once

#include "matrix.h"

class Vertex
{
public:
    Vertex() = default;
    Vertex(double v);
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

    bool operator==(const Vertex &other) const noexcept;
    bool isEqual(const Vertex &other) const noexcept;

    bool operator!=(const Vertex &other) const noexcept;
    bool isNotEqual(const Vertex &other) const noexcept;

    Vertex operator+(const Vertex &other) const;
    Vertex operator-(const Vertex &other) const;
    Vertex operator*(const Vertex &other) const;
    Vertex operator*(const double &coef) const;

    Vertex &operator+=(const Vertex &other);
    Vertex &operator-=(const Vertex &other);

    Vertex getAbsVertex(const Vertex &center);
    void normalize();
    
    Vertex getCenter() const;
    void transform(const Matrix<double> &mat);

    static Vertex crossProduct(const Vertex &a, const Vertex &b) noexcept;
    static double dotProduct(const Vertex &a, const Vertex &b) noexcept;

private:
    double m_x;
    double m_y;
    double m_z;
};
