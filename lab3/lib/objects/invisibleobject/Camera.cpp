#include "Camera.h"

Camera::Camera(const Vertex &location, const Vertex &direction)
    : m_location(location),
      m_direction(direction)
{
    m_direction = {0, 1, 0};
    updateAxes();

    qDebug() << m_direction.getX() << " " << m_direction.getY() << " " << m_direction.getZ();
}

Vertex Camera::getCenter() const
{
    return m_location;
}

void Camera::transform(const Matrix<double> &mat, const Vertex &center)
{
    Vertex diff = Vertex(0) - center;
    m_location += diff;

    Matrix<double> cur_location = {{m_location.getX(), m_location.getY(), m_location.getZ(), 1}};
    Matrix<double> new_location = cur_location * mat;

    Matrix<double> cur_direction = {{m_direction.getX(), m_direction.getY(), m_direction.getZ(), 1}};
    Matrix<double> new_direction = cur_direction * mat;

    m_location = Vertex(new_location[0][0], new_location[0][1], new_location[0][2]);
    m_direction = Vertex(new_direction[0][0], new_direction[0][1], new_direction[0][2]);

    updateAxes();

    m_location -= diff;
}

void Camera::updateAxes()
{
    m_direction.normalize();

    Vertex up = Vertex(0, 0, 1);
    m_right = Vertex::crossProduct(up, m_direction);
    m_up = Vertex::crossProduct(m_direction, m_right);

    m_up.normalize();
    m_right.normalize();

    qDebug() << m_right.getX() << " " << m_right.getY() << " " << m_right.getZ();
}
