#include <cmath>

#include "Vertex.h"

double toRadians(const double angle)
{
    return angle * (M_PI / 180);
}

Vertex::Vertex(const double x, const double y, const double z)
    : m_x(x),
      m_y(y),
      m_z(z)
{
}


Vertex::Vertex(const Vertex &&point) noexcept
{
    setX(point.m_x);
    setY(point.m_y);
    setZ(point.m_z);

    point.~Vertex();
}


Vertex &Vertex::operator=(Vertex &&point) noexcept
{
    setX(point.m_x);
    setY(point.m_y);
    setZ(point.m_z);

    point.~Vertex();

    return *this;
}

double Vertex::getX() const noexcept
{
    return m_x;
}

double Vertex::getY() const noexcept
{
    return m_y;
}

double Vertex::getZ() const noexcept
{
    return m_z;
}

void Vertex::setX(const double x)
{
    m_x = x;
}

void Vertex::setY(const double y)
{
    m_y = y;
}

void Vertex::setZ(const double z)
{
    m_z = z;
}

bool Vertex::operator==(const Vertex &point) const noexcept
{
    return (point.m_x == m_x) && (point.m_y == m_y) && (point.m_z == m_z);
}

bool Vertex::isEqual(const Vertex &point) const noexcept
{
    return *this == point;
}

bool Vertex::operator!=(const Vertex &point) const noexcept
{
    return !(*this == point);
}

bool Vertex::isNotEqual(const Vertex &point) const noexcept
{
    return !(*this == point);
}

Vertex Vertex::operator+(const Vertex &point) const
{
    Vertex d{*this};

    d.setX(d.m_x + point.m_x);
    d.setY(d.m_y + point.m_y);
    d.setZ(d.m_z + point.m_z);

    return d;
}

Vertex Vertex::operator-(const Vertex &point) const
{
    Vertex d{*this};

    d.setX(d.m_x - point.m_x);
    d.setY(d.m_y - point.m_y);
    d.setZ(d.m_z - point.m_z);

    return d;
}


void Vertex::transform(const Matrix<double> &mat)
{
    Matrix<double> cur_location = {{m_x, m_y, m_z, 1}};
    Matrix<double> new_location = cur_location * mat;

    m_x = new_location[0][0];
    m_y = new_location[0][1];
    m_z = new_location[0][2];
}

Vertex Vertex::getCenter() const
{
    return *this;
}

Vertex Vertex::getAbsVertex(const Vertex &center)
{
    return (*this) + center;
}
