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
    Vertex projection = point;

    Matrix<double> rot = TransformMatrix::createRotationMatrix4(
        m_camera->m_angle.getX(),
        m_camera->m_angle.getY(),
        m_camera->m_angle.getZ()
    );

    Matrix<double> translation = TransformMatrix::createTranslationMatrix4(
        m_camera->m_location.getX(),
        m_camera->m_location.getY(),
        m_camera->m_location.getZ()
    );

    projection.transform(rot * translation);
    return projection;
}

void DrawCarcassModelAdapter::request()
{
    if (m_adaptee && m_camera && m_drawer)
    {
        auto points = m_adaptee->m_mesh->getVertices();
        auto edges = m_adaptee->m_mesh->getEdges();
        auto center = m_adaptee->m_mesh->getOrigin();

        for (const auto &edge : edges)
        {
            m_drawer->drawLine(
                getProjection(points.at(edge.getStart() - 1)).getAbsVertex(center),
                getProjection(points.at(edge.getEnd() - 1)).getAbsVertex(center)
            );
        }
    }
}
