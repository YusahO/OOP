#pragma once

#include <AbstractFactory.h>
#include <QtDrawer.h>


class QtFactory : public AbstractFactory
{
public:
    explicit QtFactory(QGraphicsScene *scene);

    std::unique_ptr<BaseDrawer> createDrawer() override;

private:
    QGraphicsScene *m_scene;
};
