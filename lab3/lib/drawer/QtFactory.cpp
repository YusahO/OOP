#include "QtFactory.h"

QtFactory::QtFactory(QGraphicsScene *scene)
{
    m_scene = scene;
}

std::unique_ptr<BaseDrawer> QtFactory::createDrawer()
{
    return std::unique_ptr<BaseDrawer>(new QtDrawer(m_scene));
}
