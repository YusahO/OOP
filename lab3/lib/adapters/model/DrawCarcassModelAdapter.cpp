#include <DrawCarcassModelAdapter.h>
#include <QColor>

#include <cmath>

#include "TransformMatrix.h"

void DrawCarcassModelAdapter::setCamera(std::shared_ptr<Camera> camera)
{
    m_camera = camera;
}

void DrawCarcassModelAdapter::setDrawer(std::shared_ptr<BaseDrawer> drawer)
{
    m_drawer = drawer;
}

Vertex DrawCarcassModelAdapter::getProjection(const Vertex &point)
{
    // double dist = 10.;
    // Vertex projection = m_camera->m_location + m_camera->m_direction * dist;
    // double dot_product = Vertex::dotProduct(point - projection, m_camera->m_right);

    // projection += m_camera->m_right * dot_product;
    // return projection;

    Vertex projection = point;

    Matrix<double> trans_1 = TransformMatrix::createTranslationMatrix4(
        -m_camera->m_location.getX(),
        -m_camera->m_location.getY(),
        -m_camera->m_location.getZ()
    );

    Matrix<double> rot = TransformMatrix::createRotationMatrix4(0, m_camera->Y_angle, m_camera->Z_angle);

    Matrix<double> trans_2 = TransformMatrix::createTranslationMatrix4(
        m_camera->m_location.getX(),
        m_camera->m_location.getY(),
        m_camera->m_location.getZ()
    );

    projection.transform(trans_1 * rot * trans_2);
    return projection;
}

void DrawCarcassModelAdapter::request()
{
    if (m_adaptee && m_camera && m_drawer)
    {
        auto points = m_adaptee->m_mesh->getVertices();
        auto edges = m_adaptee->m_mesh->getEdges();
        auto center = m_adaptee->m_mesh->getCenter();

        for (const auto &edge : edges)
        {
            m_drawer->drawLine(
                getProjection(points.at(edge.getStart() - 1)).getAbsVertex(center),
                getProjection(points.at(edge.getEnd() - 1)).getAbsVertex(center)
            );
        }
    }
}
