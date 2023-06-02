#include <DrawCarcassModelAdapter.h>

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

    projection.setX(projection.getX() + m_camera->m_location.getX());
    projection.setY(projection.getY() + m_camera->m_location.getY());

    return projection;
}

void DrawCarcassModelAdapter::request()
{
    if (m_adaptee && m_camera && m_drawer)
    {
        auto points = m_adaptee->m_data->getVertices();
        auto edges = m_adaptee->m_data->getEdges();
        auto center = m_adaptee->m_data->getCenter();

        for (auto edge : edges)
        {
            m_drawer->drawLine(getProjection(points.at(edge.getStart() - 1)).getAbsVertex(center),
                               getProjection(points.at(edge.getEnd() - 1)).getAbsVertex(center));
        }
    }
}
