#pragma once

#include <AbstractFactory.h>
#include <QtFactory.h>

template <typename Tfactory, typename Tscene>
class DrawerSolution
{
public:
    std::unique_ptr<BaseDrawer> createDrawer(Tscene *scene);
};

#include <DrawerSolution.hpp>

