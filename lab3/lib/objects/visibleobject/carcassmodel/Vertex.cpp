#include <cmath>

#include "Vertex.h"

double toRadians(const double angle)
{
    return angle * (M_PI / 180);
}

Vertex::Vertex(double v)
    : m_x(v),
      m_y(v),
      m_z(v)
{
}

Vertex::Vertex(const double x, const double y, const double z)
    : m_x(x),
      m_y(y),
      m_z(z)
{
}


Vertex::Vertex(const Vertex &&other) noexcept
{
    setX(other.m_x);
    setY(other.m_y);
    setZ(other.m_z);

    other.~Vertex();
}


Vertex &Vertex::operator=(Vertex &&other) noexcept
{
    setX(other.m_x);
    setY(other.m_y);
    setZ(other.m_z);

    other.~Vertex();

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

bool Vertex::operator==(const Vertex &other) const noexcept
{
    return (other.m_x == m_x) && (other.m_y == m_y) && (other.m_z == m_z);
}

bool Vertex::isEqual(const Vertex &other) const noexcept
{
    return *this == other;
}

bool Vertex::operator!=(const Vertex &other) const noexcept
{
    return !(*this == other);
}

bool Vertex::isNotEqual(const Vertex &other) const noexcept
{
    return !(*this == other);
}

Vertex Vertex::operator+(const Vertex &other) const
{
    Vertex d{*this};

    d.setX(d.m_x + other.m_x);
    d.setY(d.m_y + other.m_y);
    d.setZ(d.m_z + other.m_z);

    return d;
}

Vertex Vertex::operator-(const Vertex &other) const
{
    Vertex d{*this};

    d.setX(d.m_x - other.m_x);
    d.setY(d.m_y - other.m_y);
    d.setZ(d.m_z - other.m_z);

    return d;
}

Vertex Vertex::operator*(const Vertex &other) const
{
    Vertex d{*this};

    d.setX(d.m_x * other.m_x);
    d.setY(d.m_y * other.m_y);
    d.setZ(d.m_z * other.m_z);

    return *this;
}

Vertex Vertex::operator*(const double &coef) const
{
    Vertex d{*this};

    d.setX(d.m_x * coef);
    d.setY(d.m_y * coef);
    d.setZ(d.m_z * coef);

    return *this;
}

Vertex &Vertex::operator+=(const Vertex &other)
{
    m_x += other.m_x;
    m_y += other.m_y;
    m_z += other.m_z;

    return *this;
}

Vertex &Vertex::operator-=(const Vertex &other)
{
    m_x -= other.m_x;
    m_y -= other.m_y;
    m_z -= other.m_z;

    return *this;
}


void Vertex::transform(const Matrix<double> &mat)
{
    Matrix<double> cur_location = {{m_x, m_y, m_z, 1}};
    Matrix<double> new_location = cur_location * mat;

    m_x = new_location[0][0];
    m_y = new_location[0][1];
    m_z = new_location[0][2];
}

double Vertex::dotProduct(const Vertex &a, const Vertex &b) noexcept
{
    return (a.m_x * b.m_x) + (a.m_y * b.m_y) + (a.m_z * b.m_z);
}

Vertex Vertex::crossProduct(const Vertex &a, const Vertex &b) noexcept
{
    Vertex result;

    result.m_x = a.m_y * b.m_z - a.m_z * b.m_y;
    result.m_y = -(a.m_x * b.m_z - a.m_z * b.m_x);
    result.m_z = a.m_x * b.m_y - a.m_y * b.m_x;

    return result;
}

Vertex Vertex::getOrigin() const
{
    return *this;
}

Vertex Vertex::getAbsVertex(const Vertex &center)
{
    return (*this) + center;
}

void Vertex::normalize()
{
    double length = sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
    m_x /= length;
    m_y /= length;
    m_z /= length;
}
