#pragma once

#include <memory>
#include "SceneManager.h"

class SceneManagerCreator
{
public:
    std::shared_ptr<SceneManager> createManager();

private:
    void createInstance();

    std::shared_ptr<SceneManager> m_manager;
};
