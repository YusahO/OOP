#include "Camera.h"

void Camera::transform(const Matrix<double> &mat, const Vertex &center)
{
    Vertex diff = Vertex(0, 0, 0) - center;
    m_location = m_location + diff;

    Matrix<double> cur_location = {{m_location.getX(), m_location.getY(), m_location.getZ(), 1}};
    Matrix<double> new_location = cur_location * mat;

    m_location = Vertex(new_location[0][0], new_location[0][1], new_location[0][2]);

    m_location = m_location - diff;
}

Camera::Camera(const Vertex &location, const Vertex &direction)
    : m_location(location),
      m_direction(direction)
{
}

Vertex Camera::getCenter() const
{
    return m_location;
}
