#include <DrawCarcassModelAdapter.h>
#include <QColor>

#include <cmath>

#include "Transformer.h"

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

    Transformer transfomer;
    transfomer.setRotationMatrix(
        m_camera->m_angle.getX(),
        m_camera->m_angle.getY(),
        m_camera->m_angle.getZ()
    );

    transfomer.transform(projection);
    return projection + m_camera->m_location;
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
