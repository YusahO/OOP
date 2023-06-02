#pragma once

#include "TransformManager.h"


class TransformManagerCreator
{
public:
    std::shared_ptr<TransformManager> createManager();

private:
    void createInstance();

    std::shared_ptr<TransformManager> m_manager;
};

