#include <QtDrawer.h>

QtDrawer::QtDrawer(QGraphicsScene *scene)
{
    m_scene = scene;
}


QtDrawer::QtDrawer(const QtDrawer &drawer)
{
    m_scene = drawer.m_scene;
}

void QtDrawer::drawLine(const Vertex &vertex1, const Vertex &vertex2)
{
    m_scene->addLine(vertex1.getX(), vertex1.getY(), vertex2.getX(), vertex2.getY(), QPen({0, 0, 0}));
}


void QtDrawer::clearScene()
{
    m_scene->clear();
}
