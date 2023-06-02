#pragma once

#include <memory>

#include "LoadManager.h"

class LoadManagerCreator
{
public:
    std::shared_ptr<LoadManager> createManager();

private:
    void createInstance();

    std::shared_ptr<LoadManager> m_manager;
};
