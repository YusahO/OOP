#pragma once

#include "DrawManager.h"

class DrawManagerCreator
{
public:
    std::shared_ptr<DrawManager> createManager();

private:
    void createInstance();

    std::shared_ptr<DrawManager> m_manager;
};
